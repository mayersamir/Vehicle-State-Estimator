/*
 * LED_Interface.h
 *
 *  Created on: Oct 22, 2019
 *      Author: AVE-LAP-070
 */

#ifndef HAL_HAL_INCLUDES_LED_INCLUDES_LED_INTERFACE_H_
#define HAL_HAL_INCLUDES_LED_INCLUDES_LED_INTERFACE_H_

#define LED_ON     1
#define LED_OFF    0

void AVE_InitializeLeds(void);

void AVEManipulateLeds(uint8 state);

void AVEManipulateLed(uint8 ledNumber,uint8 ledPort,uint8 state);



#endif /* HAL_HAL_INCLUDES_LED_INCLUDES_LED_INTERFACE_H_ */
