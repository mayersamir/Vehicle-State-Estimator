/*
 * PBUTTON_Configuration.h
 *
 *  Created on: Oct 22, 2019
 *      Author: AVE-LAP-070
 */

#ifndef HAL_HAL_INCLUDES_PBUTTON_INCLUDES_PBUTTON_CONFIGURATION_H_
#define HAL_HAL_INCLUDES_PBUTTON_INCLUDES_PBUTTON_CONFIGURATION_H_

#define NUMBER_OF_PBUTTONS  2

uint8 PBUTTONS_BITS[NUMBER_OF_PBUTTONS] = {BIT4,BIT2};
uint8 PBUTTONS_PORTS[NUMBER_OF_PBUTTONS] = {MYPORTC,MYPORTD};


#endif /* HAL_HAL_INCLUDES_PBUTTON_INCLUDES_PBUTTON_CONFIGURATION_H_ */
