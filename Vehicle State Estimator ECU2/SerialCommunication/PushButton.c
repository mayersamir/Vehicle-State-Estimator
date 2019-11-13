/*
 * PBUTTON_Source.c
 *
 *  Created on: Oct 22, 2019
 *      Author: AVE-LAP-070
 */

#include "Typedefs.h"

#include "BitMasking_Macros.h"
#include "Gpio.h"

#include "PushButton.h"

#include "PushButtonCfg.h"

#include "PushButtonPrivate.h"


void intializePButtons(void)
{


	for(uint8 i =0;i<NUMBER_OF_PBUTTONS;i++)
	{
		Gpio_PinDirection(PBUTTONS_PORTS[i],PBUTTONS_BITS[i],SET_IN);
	}

}

void readPButton(uint8 portNumber,uint8 pinNumber,uint8* returnedValue)
{
	uint8 value;
	value = Gpio_PinRead(portNumber,pinNumber);
	*returnedValue = value;


}
