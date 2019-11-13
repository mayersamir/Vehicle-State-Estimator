/*
 * PBUTTON_Source.c
 *
 *  Created on: Oct 22, 2019
 *      Author: AVE-LAP-070
 */

#include "../../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"

#include "../../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "Dio.h"

#include "PushButton.h"

#include "PushButtonCfg.h"

#include "PushButtonPrivate.h"


void intializePButtons(void)
{


	for(uint8 i =0;i<NUMBER_OF_PBUTTONS;i++)
	{
		AVE_gpioPinDirection(PBUTTONS_PORTS[i],PBUTTONS_BITS[i],INPUT);
	}

}

void readPButton(uint8 portNumber,uint8 pinNumber,uint8* returnedValue)
{
	uint8 value;
	AVE_gpioPinRead(portNumber,pinNumber,&value);
	*returnedValue = value;


}
