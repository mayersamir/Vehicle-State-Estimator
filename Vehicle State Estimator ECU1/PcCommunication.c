/*
 * PcCommunication.c
 *
 *  Created on: Nov 13, 2019
 *      Author: AVE-LAP-070
 */


#include "Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "Libraries/LIBRARIES_INCLUDES/SW_Delay.h"
#include "Usart.h"
#include "SpiCfg.h"
#include "Spi.h"
#include "SpiManager.h"
#include "PcCommunication.h"
#include "Dio.h"
#include "PushButton.h"
#include "SW_Delay.h"
static volatile uint8 endInit = 0;

static uint32 InitialTime = 0;
static uint32 InitialSpeed = 0;

static uint8 endCharacter = '-';



void pcCommunicationInit(void)
{


	AVE_gpioPinDirection(PORTD,BIT0,INPUT);
	AVE_gpioPinDirection(PORTD,BIT1,OUTPUT);
	usart_Init();
	SpiManipulateMode(SPI_MASTER);

	intializePButtons();


}



void asTD(uint8* value)
{

	*value = *value - 48;

	return;
}


static void sendInitialization(void)
{


	for(uint8 i = 0;i<=0;i++)
	{
		SpiSendData((InitialTime>>(8*(i))),SEND);
		usartSendPolling((InitialTime>>(8*(i)))+'0');

	}
	for(uint8 i = 0;i<=0;i++)
	{
		SpiSendData((InitialSpeed>>(8*(i))),SEND);
		usartSendPolling((InitialSpeed>>(8*(i)))+'0');

	}
	//SpiSendData(((uint8)InitialSpeed),SEND);

}

void setInitialValues(void)
{
	static volatile uint8 counter = 0;

	static volatile uint8 flag = 0;
	uint8 value = getDataPolling();
	//usartSendPolling(value);
	asTD(&value);

	//counter++;


	while(flag == 0)
	{
		InitialTime |= ((uint32)value<<(8*counter));
		value = getDataPolling();
		if(value=='-')
		{
			flag = 1;
		}
		asTD(&value);
		counter++;
	}
	counter = 0;
	while(flag == 1)
	{

		value = getDataPolling();
		if(value!='-')
		{
			asTD(&value);

			InitialSpeed |= ((uint32)value<<(8*counter));//((uint32)value<<(7*(counter)));

			counter++;
		}
		else if(value=='-')
		{
			flag = 2;
//			uint8 something = flag * (uint8)InitialTime;
			//usartSendPolling((((uint8)(InitialTime>>7))+'0'));
			//usartSendPolling(InitialSpeed+'0');

//			for(uint8 i =0;i<3;i++)
//			{
//
//				usartSendPolling(((uint32)InitialTime>>(8*i))+'0');
//
//			}
			sendInitialization();
			endInit=1;

		}
		else
		{

		}




	}

	return;

#if 0
	if(counter<5)
	{
		InitialTime |= ((uint32)value<<(7*counter));
		//counter++;
	}
	else if(counter<9)
	{
		InitialSpeed |= ((uint32)value<<(7*(counter-5)));



	}
	else
	{
		usartSendPolling((((uint8)InitialTime)));
		endInit=1;
		//counter = 0;

		return;
	}






#endif


}

void updateSpeed(void)
{
	static volatile uint8 pressedButton1 = 0;
	static volatile uint8 pressedButton2 = 0;
	uint8 PBReadValue1,PBReadValue2;

	readPButton(PORTC,BIT4,&PBReadValue1);
	readPButton(PORTB,BIT2,&PBReadValue2);

	if(InitialSpeed >= 9)
	{
		InitialSpeed = 0;
	}
	else if(InitialSpeed<=0)
	{
		InitialSpeed = 1;
	}

	if(!pressedButton1&&PBReadValue1)
	{
		pressedButton1 =1 ;
		InitialSpeed++;
		SpiSendData(InitialSpeed,SEND);
		pressedButton2 =0;
		SW_Delay_ms(300);

	}
	else if(!pressedButton2&&PBReadValue2)
	{
		pressedButton2 = 1;
		InitialSpeed--;
		SpiSendData(InitialSpeed,SEND);
		pressedButton1 = 0;
		SW_Delay_ms(300);
	}
	else
	{
		pressedButton2 = 0;
		pressedButton1 = 0;
		SW_Delay_ms(300);
	}



}

uint8 getInitStatus(void)
{
	return endInit;
}







