/*
 * EXTI_Configuration.h
 *
 *  Created on: Oct 26, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPTCFG_H_
#define MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPTCFG_H_


#define NUMBER_OF_USED_EXTI      1

uint8 arrOfUsedExternalInterrupt[EXTI_RISING_EDGE] = {INT0_EN};

uint8 arrOfUsedExternalInterruptModes[EXTI_RISING_EDGE] = {EXTI_RISING_EDGE};





#endif /* MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPTCFG_H_ */
