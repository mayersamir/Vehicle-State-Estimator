/*
 * 7SEGMENT_SRC.c
 *
 *  Created on: Oct 23, 2019
 *      Author: AVE-LAP-070
 */


#include "../../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"

#include "../../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "../../../Libraries/LIBRARIES_INCLUDES/SW_Delay.h"
#include "Dio.h"
#include "SevenSegment.h"

#include "SevenSegmentCfg.h"

#include "SevenSegmentPrivate.h"



void enableSegment(uint8 segmentPort,uint8 segmentPin,uint8 segmentEnable)
{


	switch(segmentEnable)
	{

	case SEGMENT_ENABLE:
		AVE_gpioPinWrite(segmentPort, segmentPin,HIGH);
		break;
	case SEGMENT_DISABLE:
		AVE_gpioPinWrite(segmentPort, segmentPin,LOW);
		break;



	}




}

void intialize_7SEGMENT(void)
{


	for(uint8 i = 0;i<NUMBER_OF_7SEGMENT;i++)
	{

		AVE_gpioPinDirection(arrOfEnablePorts[i],arrOfEnablePins[i],OUTPUT);
		AVE_gpioPinWrite(arrOfEnablePorts[i],arrOfEnablePins[i],LOW);
	}

	for(uint8 i = 0;i<NUMBER_OF_7SEGMENT;i++)
	{
		for(uint8 j = 0;j<NUMBER_OF_PINS;j++)
		{
			AVE_gpioPinDirection(arrOfPinsPorts[i][j],arrOfPins[i][j],OUTPUT);
			//AVE_gpioPinWrite(arrOfPinsPorts[i][j],arrOfPins[i][j],HIGH);
		}
	}
}


void visualizeNumber(uint8 number)
{

	if(number<=9)
	{
		enableSegment(PORTD,BIT3,SEGMENT_DISABLE);
		enableSegment(PORTD,BIT2,SEGMENT_ENABLE);

		AVE_gpioLowerNibbleWrite(PORTB,arrOfAvailableNumbers[number]);


	}
	else
	{

		enableSegment(PORTD,BIT3,SEGMENT_DISABLE);
		enableSegment(PORTD,BIT2,SEGMENT_ENABLE);
		AVE_gpioLowerNibbleWrite(PORTB,((arrOfAvailableNumbers[number])));
		SW_Delay_ms(5);
		enableSegment(PORTD,BIT2,SEGMENT_DISABLE);
		enableSegment(PORTD,BIT3,SEGMENT_ENABLE);
		AVE_gpioLowerNibbleWrite(PORTB,((arrOfAvailableNumbers[number]>>4)));
		SW_Delay_ms(5);


	}



}



