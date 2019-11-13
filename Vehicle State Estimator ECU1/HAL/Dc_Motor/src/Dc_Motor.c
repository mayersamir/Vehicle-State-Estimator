/*
 * DC_Motor.c
 *
 *  Created on: Nov 5, 2019
 *      Author: AVE-LAP-070
 */

#include "../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "Dio.h"
#include "TimerLcfg.h"
#include "Timer.h"

#include "Dc_Motor.h"
#include "Dc_MotorCfg.h"






extern timerCfg timerPostCfgStruct2;


void DC_Motor_Init(uint8 Channel)
{
	switch(Channel)
	{

	case DC_Motor_Channel_0:
		AVE_gpioPinDirection(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,OUTPUT);
		AVE_gpioPinDirection(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,OUTPUT);
		break;
	case DC_Motor_Channel_1:
		AVE_gpioPinDirection(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,OUTPUT);
		AVE_gpioPinDirection(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,OUTPUT);
		break;
	default:
		break;



	}

	timerPostCfgStruct2.linkingType = PRELINKING;

	AVE_timer1Init(&timerPostCfgStruct2);
	AVE_gpioPinDirection(PORTD,BIT5,OUTPUT);

	return;



}

STATUS DC_Motor_Set_Speed(uint8 Speed)
{

	Ave_timer1PWM(Speed,20);

	return E_OK;






}

STATUS DC_Motor_Set_Direction(uint8 Channel , uint8 Direction)
{

	switch(Direction)
	{

	case DC_Motor_Back:
		switch(Channel)
		{
		case DC_Motor_Channel_0:
			AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,LOW);
			AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,HIGH);
			break;
		case DC_Motor_Channel_1:

			AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,LOW);
			AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,HIGH);
			break;
		}

		break;
	case DC_Motor_Forward:
		switch(Channel)
		{
		case DC_Motor_Channel_0:
			AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,HIGH);
			AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,LOW);
			break;
		case DC_Motor_Channel_1:
			AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,HIGH);
			AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,LOW);
			break;


		}


		break;
	case DC_Motor_Right:
		switch(Channel)
		{
		case DC_Motor_Channel_0:
			AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,LOW);
			AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,HIGH);
			break;
		case DC_Motor_Channel_1:
			AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,HIGH);
			AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,LOW);
			break;


		}


		break;
	case DC_Motor_Left:
		switch(Channel)
		{
		case DC_Motor_Channel_0:
			AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,HIGH);
			AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,LOW);
			break;
		case DC_Motor_Channel_1:
			AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,LOW);
			AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,HIGH);
			break;



		}


		break;

	}
	return E_OK;

}

void DC_Motor_Stop(uint8 Channel)
{

	switch(Channel)
	{

	case DC_Motor_Channel_0:
		AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,LOW);
		AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,LOW);
		break;
	case DC_Motor_Channel_1:
		AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,LOW);
		AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,LOW);
		break;



	}




}

void DC_Motor_Start(uint8 Channel)
{

	switch(Channel)
	{

	case DC_Motor_Channel_0:
		AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_1,HIGH);
		AVE_gpioPinWrite(DC_MOTOR_Channel_0_Port,DC_MOTOR_Channel_0_Pin_2,LOW);
		break;
	case DC_Motor_Channel_1:
		AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_1,HIGH);
		AVE_gpioPinWrite(DC_MOTOR_Channel_1_Port,DC_MOTOR_Channel_1_Pin_2,LOW);
		break;




	}



}
