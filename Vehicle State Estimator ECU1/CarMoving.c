/*
 * CarMoving.c
 *
 *  Created on: Oct 28, 2019
 *      Author: AVE-LAP-070
 */

#include"Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "Libraries/LIBRARIES_INCLUDES/SW_Delay.h"
#include "Dio.h"
#include "Dir_Control.h"
#include "TimerLcfg.h"
#include "Timer.h"
#include "Ext_Interrupt.h"


#include "Ultrasonic.h"

typedef enum carState
{
	CarStart,
	CarForward,
	CarBackward,
	CarSlowDown,
	CarRotate,
	CarStop
}CARSTATE;

CARSTATE currentState = CarStart;


void initializeCar(void)
{

	//AVE_gpioLowerNibbleDirection(PORTA,OUTPUT);


	//Ave_timer1PWM(80,20);
	initializeControl();
	initializeUltraSonic();
	triggerUltrasonic();

	return ;


}


void controlCar(void)
{

	uint32 distance = calculateDistance();

	switch(distance)
	{

	case 40 ... 79:

	Motor_Speed(40);
	move_Forward();
	break;

	case 31 ... 39:
	Motor_Speed(30);
	move_RotateRight();
	SW_Delay_ms(500);
	break;

	case 1 ... 29:
	Stop();
	SW_Delay_ms(100);
	Motor_Speed(40);
	move_Backward();
	SW_Delay_ms(90);
	move_RotateRight();
	SW_Delay_ms(100);

	if(distance>20)
	{
		move_RotateRight();
		Motor_Speed(30);
		SW_Delay_ms(500);
	}
	break;

	case 0:
	Motor_Speed(60);
	move_Forward();
	break;




	}




	return ;
}



#if 0
//
//void moveBackward(void)
//{
//	AVE_gpioPinWrite(PORTA,BIT0,LOW);
//	AVE_gpioPinWrite(PORTA,BIT1,HIGH);
//	AVE_gpioPinWrite(PORTA,BIT2,LOW);
//	AVE_gpioPinWrite(PORTA,BIT3,HIGH);
//}
//
//
//void moveForward(void)
//{
//	AVE_gpioPinWrite(PORTA,BIT0,HIGH);
//	AVE_gpioPinWrite(PORTA,BIT1,LOW);
//	AVE_gpioPinWrite(PORTA,BIT2,HIGH);
//	AVE_gpioPinWrite(PORTA,BIT3,LOW);
//}
//
//void moveRight(void)
//{
//	AVE_gpioPinWrite(PORTA,BIT0,LOW);
//	AVE_gpioPinWrite(PORTA,BIT1,HIGH);
//	AVE_gpioPinWrite(PORTA,BIT2,HIGH);
//	AVE_gpioPinWrite(PORTA,BIT3,LOW);
//
//}
//
//void notMoving(void)
//{
/**
 *
 *
 *
 *
 * /
//	AVE_gpioPinWrite(PORTA,BIT0,LOW);
//	AVE_gpioPinWrite(PORTA,BIT1,LOW);
//	AVE_gpioPinWrite(PORTA,BIT2,LOW);
//	AVE_gpioPinWrite(PORTA,BIT3,LOW);
//
//}
#endif
*/
#endif
