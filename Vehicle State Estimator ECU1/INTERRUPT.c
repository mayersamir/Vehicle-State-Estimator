/*
 * INTERRUPT.c
 *
 *  Created on: Oct 25, 2019
 *      Author: AVE-LAP-070
 */
#include "Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "INTERRUPT.h"

void globalInterruptManipulate(uint8 globalInterruptState)
{

	switch(globalInterruptState)
	{

	case GLOBAL_INTERRUPT_ENABLE:
		SET_BIT(SREG,SREG_I);
		break;
	case GLOBAL_INTERRUPT_DISABLE:
		CLEAR_BIT(SREG,SREG_I);
		break;

	}

	return;
}
