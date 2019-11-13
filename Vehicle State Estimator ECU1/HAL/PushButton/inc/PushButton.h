/*
 * PBUTTON_Interface.h
 *
 *  Created on: Oct 22, 2019
 *      Author: AVE-LAP-070
 */

#ifndef HAL_HAL_INCLUDES_PBUTTON_INCLUDES_PBUTTON_INTERFACE_H_
#define HAL_HAL_INCLUDES_PBUTTON_INCLUDES_PBUTTON_INTERFACE_H_

void intializePButtons(void);
void readPButton(uint8 portNumber,uint8 pinNumber,uint8* returnedValue);

#endif /* HAL_HAL_INCLUDES_PBUTTON_INCLUDES_PBUTTON_INTERFACE_H_ */
