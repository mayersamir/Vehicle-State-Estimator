/*
 * Usart.c
 *
 *  Created on: Nov 10, 2019
 *      Author: AVE-LAP-070
 */

#include "Typedefs.h"
#include "BitMasking_Macros.h"
#include "Usart.h"
#include "Usart_Cfg.h"
#include "Interrupts.h"
#include "Gpio.h"



typedef struct callbackfunctions
{
	void (*txCallBack)(void);
	void (*rxCallBack)(void);
	void (*udrCallBack)(void);
}CallBackFunctions;


static volatile CallBackFunctions cbs;

static volatile uint8 receivedValue = 0;

static uint8 bitNinthFlag = 0;

static volatile uint16 dataToBeSent ;

/*
 * Function : get_Ubbr_Value
 * Param_In : Name\baud
 * 			  Type\uint32
 * 			  Desc\this represents the baud rate that is going
 * 			  		to be used for usart transmit or recieve.
 * 			  Name\flag
 * 			  Type\uint8
 * 			  Desc\this flag indicates whether the mode of usart
 * 			  		is asynchronous or synchrounous or even
 * 			  		asynchronous with double speed to be able to alter
 * 			  		the equation of getting the value that
 * 			  		can be set at the register ubbr.
 *	Ouput:    It returns the value of the ubbr applying the baudRate
 *				equation presented at the datasheet
 *	Return:    it returns the value of the ubbr register that
 *				needs to be set in order to be able to achieve the
 *				passed baud rate value .
 *
 *	Desc:      the purpose of this function is obviously to be able
 *				to set the right value of the ubbr register
 *				as it turns the baud rate and the mode that have been
 *				passed to it into a real ubrrValue that is ready
 *				to be set inside the ubrr register to get the right
 *				baudRate.
 */
static uint16 get_Ubbr_Value(uint32 baud,uint8 flag)
{
	uint16 ubrrValue = 0;

	switch(flag)
	{
	case 0:
		ubrrValue = ((uint32)FOSC/(16*baud))-1;
		break;
	case 1:
		ubrrValue = ((uint32)FOSC/(8*baud))-1;
		break;
	case 2:
		ubrrValue = ((uint32)FOSC/(2*baud))-1;
		break;
	default:
		ubrrValue = 51;
		break;
	}



	return ubrrValue;
}





/*
 * Function : usartInit
 * Param_In : void
 *	Ouput:    void
 *	Return:    void
 *
 *	Desc:      the purpose of this function is obviously to intialize
 *				the usart module
 *				it intializes the module using the pre compile config
 *				it sets the dataFrame size
 *				it sets the numberOfStopBits
 *				it sets the configuration of the usart
 *				it sets the mode of usart module
 *
 */

void usart_Init(void)
{

	uint8 UCSRC_Cfg = (1<<UCSRC_URSEL);
	uint8 asyncDoubleSpeed = 0;
	uint16 ubrrValue;


#if USART_CFG_MODE == USART_RECEIVER_CFG
	SET_BIT(USART_UCSRB,UCSRB_RXEN);
#elif USART_CFG_MODE == USART_TRANSMITTER_CFG
	SET_BIT(USART_UCSRB,UCSRB_TXEN);

#elif USART_CFG_MODE == USART_RECEIVER_TRANSMITTER_CFG
	SET_BIT(USART_UCSRB,UCSRB_RXEN);
	SET_BIT(USART_UCSRB,UCSRB_TXEN);
#else
#endif



#if USART_MODE == USART_ASYNCHRONOUS_MODE
	CLR_BIT(UCSRC_Cfg,UCSRC_UMSEL);
	asyncDoubleSpeed = 0;
#elif USART_MODE == USART_SYNCHRONUOUS_MODE
	SET_BIT(UCSRC_Cfg,UCSRC_UMSEL);
	asyncDoubleSpeed = 2;
#elif USART_MODE == USART_ASYNCHRONOUS_MPCM_MODE
	CLR_BIT(UCSRC_Cfg,UCSRC_UMSEL);
	SET_BIT(USART_UCSRA,UCSRA_MPCM);
	asyncDoubleSpeed = 2;
#elif USART_MODE == USART_SYNCHRONOUS_MPCM_MODE
	SET_BIT(UCSRC_Cfg,UCSRC_UMSEL);
	SET_BIT(USART_UCSRA,UCSRA_MPCM);
	asyncDoubleSpeed = 2;
#elif USART_MODE == USART_ASYNCHRONOUS_DOUBLE_MODE
	CLR_BIT(UCSRC_Cfg,UCSRC_UMSEL);
	SET_BIT(USART_UCSRA,UCSRA_U2X);
	asyncDoubleSpeed = 1;
#else



#endif




#if USART_PARITY == USART_PARITY_DISABLED
	CLR_BIT(UCSRC_Cfg,UCSRC_UPM0);
	CLR_BIT(UCSRC_Cfg,UCSRC_UPM1);
#elif USART_PARITY == USART_PARITY_EVEN
	SET_BIT(UCSRC_Cfg,UCSRC_UPM1);
	CLR_BIT(UCSRC_Cfg,UCSRC_UPM0);
#elif USART_PARITY == USART_PARITY_ODD
	SET_BIT(UCSRC_Cfg,UCSRC_UPM0);
	SET_BIT(UCSRC_Cfg,UCSRC_UPM1);
#else
#endif

#if USART_STOP_BITS == USART_1BIT_STOP
	CLR_BIT(UCSRC_Cfg,UCSRC_USBS);
#elif USART_STOP_BITS == USART_2BIT_STOP
	SET_BIT(UCSRC_Cfg,UCSRC_USBS);
#else
#endif


#if USART_DATA_FRAME_BITS == USART_8BIT_DATA
	SET_BIT(UCSRC_Cfg,UCSRC_UCSZ0);
	SET_BIT(UCSRC_Cfg,UCSRC_UCSZ1);
	CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
#elif USART_DATA_FRAME_BITS == USART_5BIT_DATA
	CLR_BIT(UCSRC_Cfg,UCSRC_UCSZ0);
	CLR_BIT(UCSRC_Cfg,UCSRC_UCSZ1);
	CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
#elif USART_DATA_FRAME_BITS == USART_6BIT_DATA
	SET_BIT(UCSRC_Cfg,UCSRC_UCSZ0);
	CLR_BIT(UCSRC_Cfg,UCSRC_UCSZ1);
	CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
#elif USART_DATA_FRAME_BITS == USART_7BIT_DATA
	CLR_BIT(UCSRC_Cfg,UCSRC_UCSZ0);
	SET_BIT(UCSRC_Cfg,UCSRC_UCSZ1);
	CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
#elif USART_DATA_FRAME_BITS == USART_9BIT_DATA
	SET_BIT(UCSRC_Cfg,UCSRC_UCSZ0);
	SET_BIT(UCSRC_Cfg,UCSRC_UCSZ1);
	SET_BIT(USART_UCSRB,UCSRB_UCSZ2);
	bitNinthFlag = 1;
#else
#endif

#if USART_POLARITY == USART_RTRANSMIT_FRECEIVE
	CLR_BIT(UCSRC_Cfg,UCSRC_UCPOL);
#elif USART_POLARITY == USART_PTRANSMIT_RRECEIVE
	SET_BIT(UCSRC_Cfg,UCSRC_UCPOL);
#else
#endif





	USART_UCSRC = UCSRC_Cfg;
	ubrrValue = get_Ubbr_Value(USART_BAUDRATE,asyncDoubleSpeed);
	USART_UBRRH = (ubrrValue>>8);
	USART_UBRRL = (ubrrValue);


#if 0
	USART_UCSRB =  ((1 << UCSRB_TXEN)|(1<<UCSRB_RXEN));   // Turn on the transmission and reception circuitry
	USART_UCSRC = (1 << UCSRC_URSEL) | (1 << UCSRC_UCSZ0) | (1 << UCSRC_UCSZ1); // Use 8-bit character sizes
	//USART_UCSRB |= (1 << UCSRB_RXCIE);

	USART_UBRRH = 0;//(BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	USART_UBRRL = 51;//BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register

	SET_BIT(USART_UCSRB,UCSRB_RXCIE);
	cbs.rxCallBack = NULL;
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);

#endif

	return ;

}


/*
 * Function : usartSendPolling
 * Param_In : Name\value
 *	Ouput:    Type\uin16
 *	Return:   Desc\this value is for holding the value that needs to
 *				be sent through the uart module,may or may not
 *				contatin the ninth bit if it is already set for the
 *				module to be intialized to send dataframe of 9 bits
 *
 *
 *	Desc:      the purpose of this function is obviously to intialize
 *				the usart module
 *				it intializes the module using the pre compile config
 *				it sets the dataFrame size
 *				it sets the numberOfStopBits
 *				it sets the configuration of the usart
 *				it sets the mode of usart module
 *
 */

void usartSendPolling(uint16 value)
{


	if(bitNinthFlag)
	{
		if(value>>8)
		{
			SET_BIT(USART_UCSRB,UCSRB_TXB8);
		}
		else
		{
			CLR_BIT(USART_UCSRB,UCSRB_TXB8);
		}
	}




	while(!(USART_UCSRA & (1<<UCSRA_UDRE)));


	USART_UDR  = value;

	return;

}


/*
 * Function : getDataPolling
 * Param_In : void
 *	Ouput:    Type\uint16
 *			  Desc\this for returning the sent variable
 *			  through the usart module
 *	Return:   void
 *
 *	Desc:      the purpose of this function is
 *				to get the sent data through the usart module
 *				it waits for the flag then it returns the contents
 *				of the register udr as a returned from function.
 *
 */

uint16 getDataPolling(void)
{

	uint16 data ;

	while(!(USART_UCSRA&(1<<UCSRA_RXC)));

//	if(bitNinthFlag)
//	{
//		bitNinthFlag = GET_BIT(USART_UCSRB,UCSRB_RXB8);
//	}

	data = USART_UDR;

//	if(bitNinthFlag)
//	{
//		data |= (1<<8);
//	}
	return data;

}




void setRecieveCallBack(void (*ptf)(void))
{
	cbs.rxCallBack = ptf;
}

void setTransmitCallBack(void (*ptf)(void))
{
	cbs.txCallBack = ptf;
}

void setUdrCallBack(void (*ptf)(void))
{
	cbs.udrCallBack = ptf;
}



uint8 getTransmittedData(void)
{
	return receivedValue;
}


/*
 * Function :TransmitHandler
 * Param : In:void
 * 		   Out:void
 * Return: void
 * Desc: this function is a special function for handling the
 * interrupt that is raised if the transmission of a frame through
 * the usart module is completed .
 * you need to set the value to be transmitted using the usartSetTValue
 * in order for that function to fire properly.
 *
 */
USART_TXC_Handler()
{
	if(cbs.txCallBack != 0)
	{
		cbs.txCallBack();
	}
	else
	{


	}
	if(bitNinthFlag)
	{
		if(dataToBeSent>>8)
		{
			SET_BIT(USART_UCSRB,UCSRB_TXB8);
		}
		else
		{
			CLR_BIT(USART_UCSRB,UCSRB_TXB8);
		}
	}
	USART_UDR  = dataToBeSent;


}


USART_RXC_Handler()
{
	if(bitNinthFlag)
	{
		bitNinthFlag = GET_BIT(USART_UCSRB,UCSRB_RXB8);
	}

	receivedValue = USART_UDR;
	if(bitNinthFlag)
	{
		receivedValue |= (1<<8);
	}
	USART_UDR = receivedValue;
	if(cbs.rxCallBack!=0)
	{
		cbs.rxCallBack();
	}
	else
	{

	}


#if 0
	char ReceivedByte;
	   ReceivedByte = USART_UDR; // Fetch the received byte value into the variable "ByteReceived"
	   USART_UDR = ReceivedByte;


	   if(ReceivedByte == 'a')
	   {
		   cbs.rxCallBack();
	   }
	   else
	   {
		   //AVEManipulateLed(BIT6,PORTB,LED_OFF);
	   }
#endif
}


//ISR(INT12_USART_RXC)
//{
//
//
//
//}
