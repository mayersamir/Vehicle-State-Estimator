/*
 * Usart.h
 *
 *  Created on: Nov 9, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_USART_INC_USART_H_
#define MCAL_USART_INC_USART_H_



#define USART_UDR               *((reg_type)(0x2C))


#define UCSRA_RXC               7
#define UCSRA_TXC               6
#define UCSRA_UDRE              5
#define UCSRA_FE                4
#define UCSRA_DOR               3
#define UCSRA_PE                2
#define UCSRA_U2X               1
#define UCSRA_MPCM              0
#define USART_UCSRA             *((reg_type)(0x2B))



#define UCSRB_RXCIE             7
#define UCSRB_TXCIE             6
#define UCSRB_UDRIE             5
#define UCSRB_POLE              4
#define UCSRB_RXEN              4
#define UCSRB_TXEN              3
#define UCSRB_UCSZ2             2
#define UCSRB_RXB8              1
#define UCSRB_TXB8              0
#define USART_UCSRB             *((reg_type)(0x2A))

/*
 * the upComing register address definition is sharable by other
 * usart register Look at the datasheet in case that you need to
 * know how to handle the mess that atmega presented.
 * in case you already know it is just a kind remainder !
 * look at the section where the bit number 7 URSEL is manipulated in
 * both registers .
 */

#define UCSRC_URSEL             7
#define UCSRC_UMSEL             6
#define UCSRC_UPM1              5
#define UCSRC_UPM0              4
#define UCSRC_USBS              3
#define UCSRC_UCSZ1             2
#define UCSRC_UCSZ0             1
#define UCSRC_UCPOL             0
#define USART_UCSRC             *((reg_type)(0x40))


#define UBRRH_URSEL             7
#define USART_UBRRH             *((reg_type)(0x40))

#define USART_UBRRL             *((reg_type)(0x29))




/*
 * USART MODES DEFINTION
 */

#define USART_ASYNCHRONOUS_MODE                    0
#define USART_SYNCHRONUOUS_MODE                    1
/*
 *
 * option if you are going to connect many ucs using uart
 * so an address will be needed for each one to be able to
 * communicate successfully !
 */
#define USART_ASYNCHRONOUS_MPCM_MODE               2
#define USART_SYNCHRONOUS_MPCM_MODE                3
/*
 *
 * option for asynchronous
 */

#define FOSC                                        16000000UL

/*
 * defintions of known BAUDRATES
 */

#define BAUD0                                      2400UL
#define BAUD1                                      4800UL
#define BAUD2                                      9600UL


#define USART_ASYNCHRONOUS_DOUBLE_MODE             4










/*
 *
 * USART configured for transmission or receiving
 */

#define USART_TRANSMITTER_CFG                       0
#define USART_RECEIVER_CFG                          1
#define USART_RECEIVER_TRANSMITTER_CFG              2









/*
 * usart parity available modes defintion
 */

#define USART_PARITY_DISABLED                      0
#define USART_PARITY_EVEN                          1
#define USART_PARITY_ODD                           2







/*
 * USART number of stop bits inside the frame
 */

#define USART_1BIT_STOP                             0
#define USART_2BIT_STOP                             1







/*
 * USART number of bits of the data inside the frame
 */

#define USART_5BIT_DATA                             0
#define USART_6BIT_DATA                             1
#define USART_7BIT_DATA                             2
#define USART_8BIT_DATA                             3
#define USART_9BIT_DATA                             4






/*
 * USART sampling and transmitting edges modification
 */

#define USART_RTRANSMIT_FRECEIVE                    0
#define USART_FTRANSMIT_RRECEIVE                    1




/*
 *
 * USART INTERRUPT Modes
 */

#define USART_POLLING                                0
#define USART_INTERRUPT_RX                           1
#define USART_INTERRUPT_TX                           2
#define USART_INTERRUPT_UDR_EMPTY                    3




#define USART_POLLING_VALUE                           ((1<<UCSRB_POLE))

/*
 *
 */


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
void usart_Init(void);

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
void usartSendPolling(uint16 value);


void setRecieveCallBack(void (*ptf)(void));

void setTransmitCallBack(void (*ptf)(void));

void setUdrCallBack(void (*ptf)(void));

uint8 getTransmittedData(void);


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
uint16 getDataPolling(void);


#endif /* MCAL_USART_INC_USART_H_ */
