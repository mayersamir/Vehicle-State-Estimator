/*
 * EXTI_Source.c
 *
 *  Created on: Oct 26, 2019
 *      Author: AVE-LAP-070
 */



#include "../../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"

#include "../../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include <Ext_Interrupt.h>
#include <Ext_InterruptCfg.h>
#include <Ext_InterruptPrivate.h>

#include "../../../INTERRUPT.h"

#include "Led.h"
#include "../../Dio/inc/Dio.h"



void (*ptToExtiCallBackFunction1)(void);

void (*ptToExtiCallBackFunction2)(void);

void (*ptToExtiCallBackFunction3)(void);



/*
 *
 * you can use the configuration file in order to configure how the three
 * external interrupts will be manipulated for your project
 * each thing is self explanatory !...
 */


void addExtiCallBackFunction(uint8 extiNumber,void (*ptf)(void))
{

	switch(extiNumber)
	{
	case INT0_EN:
		ptToExtiCallBackFunction1 = ptf;
		break;
	case INT1_EN:
		ptToExtiCallBackFunction2 = ptf;
		break;
	case INT2_EN:
		ptToExtiCallBackFunction3 = ptf;
		break;


	}
}

void enableOrDisable(uint8 extiNumber)
{

	//globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);

	switch(extiNumber)
	{

	case INT0_EN:
		SET_BIT(EXTI_GICR,GICR_INT0);
		break;
	case INT1_EN:
		SET_BIT(EXTI_GICR,GICR_INT1);
		break;
	case INT2_EN:
		SET_BIT(EXTI_GICR,GICR_INT2);
		break;



	}
}
void intitalizeExtiRunTimeChange(uint8 extiNumber,uint8 mode)
{



	//globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);

	//SET_BIT(SREG,SREG_I);

	switch(extiNumber)
	{




	case INT0_EN:

		switch(mode)
		{
		case EXTI_LOGICAL_CHANGE:
			SET_BIT(EXTI_MCUCR,MCUCR_ISC00);
			CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC01);
			break;
		case EXTI_FALLING_EDGE:
			CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC00);
			SET_BIT(EXTI_MCUCR,MCUCR_ISC01);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(EXTI_MCUCR,MCUCR_ISC00);
			SET_BIT(EXTI_MCUCR,MCUCR_ISC01);
			break;
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC00);
			CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC01);
			break;
		}
		break;
	case INT1_EN:


		switch(mode)
		{
		case EXTI_LOGICAL_CHANGE:
			SET_BIT(EXTI_MCUCR,MCUCR_ISC10);
			CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC11);
		break;
		case EXTI_FALLING_EDGE:
		    CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC10);
			SET_BIT(EXTI_MCUCR,MCUCR_ISC11);
		break;
		case EXTI_RISING_EDGE:
			SET_BIT(EXTI_MCUCR,MCUCR_ISC10);
			SET_BIT(EXTI_MCUCR,MCUCR_ISC11);
		break;
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC10);
			CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC11);
		break;


		}

		break;
	case INT2_EN:

		break;


	}


}

void intializeExti(void(*ptf)(void))
{
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);

	for(uint8 i = 0;i<NUMBER_OF_USED_EXTI;i++)
	{
		switch(arrOfUsedExternalInterrupt[i])
		{
		case INT0_EN:
			SET_BIT(EXTI_GICR,GICR_INT0);
			ptToExtiCallBackFunction1 = ptf;
			switch(arrOfUsedExternalInterruptModes[i])
			{

			case EXTI_LOGICAL_CHANGE:
				SET_BIT(EXTI_MCUCR,MCUCR_ISC00);
				CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC01);
				break;
			case EXTI_FALLING_EDGE:
				CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC00);
				SET_BIT(EXTI_MCUCR,MCUCR_ISC01);
				break;
			case EXTI_RISING_EDGE:
				SET_BIT(EXTI_MCUCR,MCUCR_ISC00);
				SET_BIT(EXTI_MCUCR,MCUCR_ISC01);
				break;
			case EXTI_LOW_LEVEL:
				CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC00);
				CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC01);
				break;


			}

			break;
		case INT1_EN:
			SET_BIT(EXTI_GICR,GICR_INT1);
			ptToExtiCallBackFunction2 = ptf;
			switch(arrOfUsedExternalInterruptModes[i])
			{

			case EXTI_LOGICAL_CHANGE:
			     SET_BIT(EXTI_MCUCR,MCUCR_ISC10);
			     CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC11);
			break;
			case EXTI_FALLING_EDGE:
			     CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC10);
			     SET_BIT(EXTI_MCUCR,MCUCR_ISC11);
			break;
			case EXTI_RISING_EDGE:
				 SET_BIT(EXTI_MCUCR,MCUCR_ISC10);
				 SET_BIT(EXTI_MCUCR,MCUCR_ISC11);
			break;
		    case EXTI_LOW_LEVEL:
				 CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC10);
				 CLEAR_BIT(EXTI_MCUCR,MCUCR_ISC11);
			break;


		   }

			break;


		case INT2_EN:
			ptToExtiCallBackFunction3 = ptf;
			SET_BIT(EXTI_GICR,GICR_INT2);

			break;


		}


	}



}


/*
 *
 * setting the call back function for the external interrupt0  in order not to violate
 * the perception of not calling mcal inside mcal
 * so that i will be creating the function inside the application an pass a pointer to it
 * to the external interrupt function !
 * indirect call.....
 */

ISR(INTO_EXTI0)
{

	ptToExtiCallBackFunction1();
//	AVEManipulateLed(BIT4,PORTB,LED_ON);
	//AVEManipulateLed(BIT4,PORTB,LED_OFF);

	//AVEManipulateLed(BIT4,PORTB,LED_ON);
}

//
//
//ISR(__vector_2)
//{
//	ptToExtiCallBackFunction2();
//
//}
//
//ISR(__vector_3)
//{
//	ptToExtiCallBackFunction3();
//}
