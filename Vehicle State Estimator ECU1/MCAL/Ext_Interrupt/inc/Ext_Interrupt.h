/*
 * EXTI_Interface.h
 *
 *  Created on: Oct 26, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPT_H_
#define MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPT_H_


#define EXTI_LOGICAL_CHANGE    0
#define EXTI_LOW_LEVEL         1
#define EXTI_FALLING_EDGE      2
#define EXTI_RISING_EDGE       3


/*
 *
 * definintion of the three available external interrupts for the atmega to be used !
 * \
 */

#define INT0_EN              0
#define INT1_EN             1
#define INT2_EN              2



void intializeExti(void (*ptf)(void));

void addExtiCallBackFunction(uint8 extiNumber,void (*ptf)(void));
void intitalizeExtiRunTimeChange(uint8 extiNumber,uint8 mode);

void enableOrDisable(uint8 extiNumber);


#endif /* MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPT_H_ */
