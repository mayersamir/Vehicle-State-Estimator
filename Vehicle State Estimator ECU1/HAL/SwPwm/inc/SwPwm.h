/*
 * swPWM.h
 *
 *  Created on: Oct 26, 2019
 *      Author: AVE-LAP-070
 */

#ifndef SWPWM_H_
#define SWPWM_H_




#define SW_PWM_TIMER0     0
#define SW_PWM_TIMER1     1
#define SW_PWM_TIMER2     2

void sw_PWMIntialize(uint8 swPwmNumber,uint8 timerInterruptMode,uint8 prescalermode,uint16 outputCompareValue);


void sw_PWMSelect(uint8 swPwmNumber,uint8 dutyCycle,uint16 frequency,void(*ptf)(void));






#endif /* SWPWM_H_ */
