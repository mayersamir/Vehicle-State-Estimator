/*
 * ICU.h
 *
 *  Created on: Oct 27, 2019
 *      Author: AVE-LAP-070
 */

#ifndef ICU_H_
#define ICU_H_


#define HW_ICU    0
#define SW_ICU    1


#define ICU_TIMER0   0
#define ICU_TIMER1   1
#define ICU_TIMER2   2






void  startCalculationIcu(void);


void SwICU_Read(uint32*Reading_value);

STATUS SwICU_Enable(void);

STATUS SwICU_Disable(void);
STATUS  SwICU_Init(uint8 timerNumber);


#endif /* ICU_H_ */
