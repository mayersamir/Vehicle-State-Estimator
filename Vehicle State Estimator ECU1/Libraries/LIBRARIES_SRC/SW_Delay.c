/*
 * SW_Delay.c
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#include "../LIBRARIES_INCLUDES/LTYPES.h"

#include "../LIBRARIES_INCLUDES/SW_Delay.h"



void SW_Delay_ms(uint32 delayValue)
{


	volatile uint32 numberOfIterations = (delayValue*1000*16)/(40);


	for(uint32 i =0;i<numberOfIterations;i++);


	return;



}


