/*
 * LED_Source.c
 *
 *  Created on: Oct 22, 2019
 *      Author: AVE-LAP-070
 */


#include "../../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"

#include "../../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"

#include "Dio.h"
#include "Led.h"
#include "LedCfg.h"
#include "LedPrivate.h"



void AVE_InitializeLeds(void)
{
	for(uint8 i =0;i<NUMBER_OF_LEDS;i++)
	{
		AVE_gpioPinDirection(LEDS_PORTS[i],LEDS_BITS[i],OUTPUT);

	}

	for(uint8 i =0;i<NUMBER_OF_LEDS;i++)
	{
		AVE_gpioPinWrite(LEDS_PORTS[i],LEDS_BITS[i],LEDS_VALUES[i]);
	}

}

void AVEManipulateLeds(uint8 state)
{

	switch(state)
	{
	case LED_ON:
		for(uint8 i =0;i<NUMBER_OF_LEDS;i++)
			{
				AVE_gpioPinWrite(LEDS_PORTS[i],LEDS_BITS[i],HIGH);
			}
		break;
	case LED_OFF:
		for(uint8 i =0;i<NUMBER_OF_LEDS;i++)
			{
				AVE_gpioPinWrite(LEDS_PORTS[i],LEDS_BITS[i],LOW);
			}
		break;

	}
}

void AVEManipulateLed(uint8 ledNumber,uint8 ledPort,uint8 state)
{

	switch(state)
	{
	case LED_ON:
		AVE_gpioPinWrite(ledPort,ledNumber,HIGH);
		break;
	case LED_OFF:
		AVE_gpioPinWrite(ledPort,ledNumber,LOW);
		break;

	}
}
