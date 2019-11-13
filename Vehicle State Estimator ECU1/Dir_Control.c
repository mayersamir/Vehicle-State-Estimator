/*
 * Dir_Control.c
 *
 *  Created on: Nov 5, 2019
 *      Author: AVE-LAP-070
 */


#include "Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "Dio.h"
#include "Dir_Control.h"
#include "Dc_Motor.h"





void initializeControl(void)
{
	DC_Motor_Init(DC_Motor_Channel_0);
	DC_Motor_Init(DC_Motor_Channel_1);
	DC_Motor_Set_Speed(80);

	return ;


}

void move_Forward(void)
{
	DC_Motor_Set_Direction(DC_Motor_Channel_0,DC_Motor_Forward);
	DC_Motor_Set_Direction(DC_Motor_Channel_1,DC_Motor_Forward);

	return ;


}
void move_Backward(void)
{
	DC_Motor_Set_Direction(DC_Motor_Channel_0,DC_Motor_Back);
	DC_Motor_Set_Direction(DC_Motor_Channel_1,DC_Motor_Back);

	return ;


}
void move_RotateRight(void)
{
	DC_Motor_Set_Direction(DC_Motor_Channel_0,DC_Motor_Right);
	DC_Motor_Set_Direction(DC_Motor_Channel_1,DC_Motor_Right);

	return ;



}
void move_RotateLeft(void)
{
	DC_Motor_Set_Direction(DC_Motor_Channel_0,DC_Motor_Left);
	DC_Motor_Set_Direction(DC_Motor_Channel_1,DC_Motor_Left);

	return ;


}
void Stop(void)
{

	DC_Motor_Stop(DC_Motor_Channel_0);
	DC_Motor_Stop(DC_Motor_Channel_1);

	return ;



}

void Motor_Speed(uint8 speed)
{

	DC_Motor_Set_Speed(speed);



	return ;
}
