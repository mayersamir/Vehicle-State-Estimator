/*
 * Dc_Motor.h
 *
 *  Created on: Nov 5, 2019
 *      Author: AVE-LABS-50
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#define DC_Motor_Back					0
#define DC_Motor_Forward				1
#define DC_Motor_Right                  2
#define DC_Motor_Left                   3

#define DC_Motor_Channel_0 				0
#define DC_Motor_Channel_1				1


void DC_Motor_Init(uint8 Channel);

STATUS DC_Motor_Set_Speed(uint8 Speed);

STATUS DC_Motor_Set_Direction(uint8 Channel , uint8 Direction);

void DC_Motor_Stop(uint8 Channel);

void DC_Motor_Start(uint8 Channel);


#endif /* DC_MOTOR_H_ */
