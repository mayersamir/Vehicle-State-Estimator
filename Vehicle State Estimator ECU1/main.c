/*
 * main.c
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */




#include "Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "Libraries/LIBRARIES_INCLUDES/SW_Delay.h"

#include "INTERRUPT.h"

#include "Led.h"

#include "PushButton.h"

#include "SevenSegment.h"


#include "Ultrasonic.h"
#include "Ext_Interrupt.h"
#include "Dir_Control.h"

#include "CarMoving.h"
#include "TimerLcfg.h"
#include "Timer.h"

#include "Dio_Private.h"
#include "Dio.h"
#include "HAL/Dc_Motor/inc/Dc_Motor.h"
#include "HAL/SwPwm/inc/SwPwm.h"


#include "Usart.h"


#include "SpiCfg.h"
#include "Spi.h"
#include "SpiManager.h"
#include "PcCommunication.h"
volatile uint8 flag = 0;

//static volatile uint8 pushedFlag = 0;
void togg(void);



//void showMessageOnSevenSegment(void);

//
//
//int main(void)
//{
//
//
//	AVE_InitializeLeds();
//
//
//	/*using the preconfiguration without including entering the .c file to the toolchain*/
////
////
////	timerPostCfgStruct.linkingType = PRELINKING;
////	AVE_TIMER0_setCallBackForInterrupt(togg);
////
////
////
////
////	AVE_MTIMER0_Initialize(&timerPostCfgStruct);
//
//
//	/*when not using the preconfiguration
//	 *
//	 *
//	 * postConfiguration
//	 */
////
////	timerPostCfgStruct.countValue = 16000;
////	timerPostCfgStruct.interruptMode = TIMER0_TOIE_NORMAL;
////	timerPostCfgStruct.mode          = TIMER;
////
//
//
//	while(1)
//	{
//
//
//	}
//
//
//
//	return 0;
//}
//
//

void togg(void)
{

	if(flag == 0)
	{

		AVEManipulateLed(BIT4,PORTB,LED_ON);
		flag = 1;
	}
	else
	{
		AVEManipulateLed(BIT4,PORTB,LED_OFF);
		flag = 0;
	}


}

#if 0
void togg2(void)
{

	if(flag22 == 0)
	{

		AVEManipulateLed(BIT5,PORTB,LED_ON);
		flag22 = 1;
	}
	else
	{
		AVEManipulateLed(BIT5,PORTB,LED_OFF);
		flag22 = 0;
	}


}

//
//
//
#endif


#if 0
int main2(void)
{
	AVE_InitializeLeds();

	initializeCar();


//	AVE_timer1Init(TIMER1_PHASE_ICR1,TIMER1_PRESCALER1024,0,0,0, TIMER1_POLLING);


//	initializeUltraSonic();
//	initializeCar();


//	Ave_timer1PWM(50,1);


	//uint32 distance=0 ;//= //getDutyCycle();

	//intitalizeIcu(ICU_TIMER0,SW_ICU);
//
	//AVE_gpioPinDirection(PORTD,BIT2,INPUT);


//
//	intitalizeExtiRunTimeChange(INT0_EN,EXTI_RISING_EDGE);
//	addExtiCallBackFunction(INT0_EN,togg);
//
//	enableOrDisable(INT0_EN);

//
//
//	uint32 value;
//
//
//
//	triggerUltrasonic();

	while(1)
	{
		controlCar();

		//AVEManipulateLed(BIT4,PORTB,LED_OFF);
//
//
//		if(value>40&&value<80)
//		{
//			Ave_timer1PWM(40,20);
//
//		}
//		else if(value>30&&value<40)
//		{
//			Ave_timer1PWM(30,20);
//			moveRight();
//			SW_Delay_ms(500);
//		}
//		else if(value<30&&value>0)
//		{
//			//Ave_timer1PWM(0,)
//			notMoving();
//
//			SW_Delay_ms(100);
//
//			Ave_timer1PWM(40,20);
//			moveBackward();
//
//			SW_Delay_ms(90);
//			moveRight();
//			SW_Delay_ms(100);
//
//			if(value>20)
//			{
//				moveRight();
//				Ave_timer1PWM(30,20);
//				SW_Delay_ms(500);
//			}
//		}
//		else
//		{
//			Ave_timer1PWM(60,20);
//			moveForward();
//
//		}
//
//		value = calculateDistance();
//



	}

}
#endif

#if 0

//
//
//int main33(void)
//{
//	AVE_InitializeLeds();
//	sw_PWMIntialize(SW_PWM_TIMER0,TIMER0_POLLING,MTIMER0_PRESCALER8,0);
//	while(1)
//	{
//		sw_PWMSelect(SW_PWM_TIMER0,20,0,togg);
//	}
//
//}
//int main2(void)
//{
//	intializePButtons();
//	intialize_7SEGMENT();
//
//	//enableSegment(PORTD,BIT2,SEGMENT_ENABLE);
//	AVE_MTIMER0_Initialize(MTIMER0_PRESCALER8,MTIMER0_NORMAL,0,TIMER0_TOIE_NORMAL);
//
//	AVE_timer1Init(TIMER1_NORMALMODE,TIMER1_PRESCALER8, 0,0,0, TIMER1_POLLING);
//	//visualizeNumber(2);
//
//
//	uint8 PBBit4Value;
//	uint8 counterPresses = 0;
//
//	uint8 times = 100;
//
//
//	uint8 read = 0;
//
//	AVE_TIMER0_setCallBackForInterrupt(showMessageOnSevenSegment);
//	AVE_MTIMER0_delay_ms(10,TIMER0_TOIE_NORMAL);
//
//
//	while(1)
//	{
//		//visualizeNumber(1);
//		while(times != 0)
//		{
//			readPButton(PORTC,BIT4,&PBBit4Value);
//			if(PBBit4Value&&read==0)
//			{
//				counterPresses++;
//				read = 1;
//				times = 100;
//				//pushedFlag = 1;
//
//				readPButton(PORTC,BIT4,&PBBit4Value);
//				//counterPresses = 3;
//
//			}
//			AVE_TIMER1_delayMs(5,TIMER1_POLLING);
//			times--;
//			readPButton(PORTC,BIT4,&PBBit4Value);
//			if(!PBBit4Value)
//			{
//				read = 0;
//			}
//
//		}
//		times = 100;
//		if(counterPresses != 0)
//		{
//			pushedFlag = counterPresses;
//		}
//
//		counterPresses = 0;
//		//pushedFlag=0;
//
//		//AVE_MTIMER0_delay_ms(1000);
//
//
//	}
//
//
//
//
//	return 0 ;
//}
//
//void showMessageOnSevenSegment(void)
//{
//	visualizeNumber(pushedFlag);
//
//}

/*
 *
 * uart trial
 */
#endif


int main(void)
{



	//AVE_InitializeLeds();

	//uint8 dataReturned;
	//setRecieveCallBack(togg);
	//usart_Init();

	//usartSendPolling('a');

//	AVE_gpioPinDirection(PORTB,BIT5,OUTPUT);
//	AVE_gpioPinDirection(PORTB,BIT6,INPUT);
//	AVE_gpioPinDirection(PORTB,BIT7,OUTPUT);
//	AVE_gpioPinDirection(PORTB,BIT4,OUTPUT);
//	AVE_gpioPinWrite(PORTB,BIT4,LOW);


	//SpiManipulateMode(SPI_MASTER);

	pcCommunicationInit();

//	usartSendPolling(47);
	while(1)
	{

		if(!getInitStatus())
		{
			setInitialValues();

		}
		else
		{
			//usartSendPolling('a');
			updateSpeed();

		}
		//usartSendPolling('a');

		//dataReturned = getTransmittedData();

//		for(uint8 i = 0;i<254;i++)
//		{
////			usartSendPolling('1');
////			SW_Delay_ms(1000);
//		}
//



//		//togg();
		//SPI_SPDR = '1';

		//GPIOA_PORT=GPIOB_DDR;
		//while(1);
		//GPIOA_PORT=SPI_SPCR;
		//togg();
		//SW_Delay_ms(1000);


		//dataReturned =getDataPolling();


//		SpiSendData('2',SEND);
//
//		SW_Delay_ms(500);
//		SpiSendData('1',SEND);
//		SW_Delay_ms(500);

		//while(1);



	}



}



