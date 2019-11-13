/*
 * Dir_Control.h
 *
 * Created: 11/5/2019 12:34:23 PM
 *  Author: Ammar Shahin
 */ 


#ifndef DIR_CONTROL_H_
#define DIR_CONTROL_H_

/************************************************************************/
/*				 Direction Control functions' Prototypes                            */
/************************************************************************/
void initializeControl(void);
void move_Forward(void);
void move_Backward(void);
void move_RotateRight(void);
void move_RotateLeft(void);
void Stop(void);
void Motor_Speed(uint8 speed);
#endif /* DIR_CONTROL_H_ */
