/*
 * ICU.c
 *
 *  Created on: Oct 27, 2019
 *      Author: AVE-LAP-070
 */






#include "../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "Icu.h"
#include "Dio.h"
#include "Led.h"
#include "../../../INTERRUPT.h"
#include "Ext_Interrupt.h"
#include "TimerLcfg.h"
#include "Timer.h"






volatile static uint32 TON;

volatile static uint8 entrant = 0;

uint8 flag2 = 0;
uint8 counts = 0;


 void startCalculationIcu(void)
{
	static uint32 T0,T1;

	if(entrant == 0)
	{
		AVEManipulateLed(BIT7,PORTB,LED_ON);

		T0 = AVE_MTIMER0_read();
		AVE_ClearIcuOverFlows();
		entrant =1;
		intitalizeExtiRunTimeChange(INT0_EN,EXTI_FALLING_EDGE);
//		if(flag == 1)
//		{
//			AVEManipulateLed(BIT6,PORTB,LED_OFF);
//
//		}
		//AVEManipulateLed(BIT6,PORTB,LED_ON);



	}
	else if(entrant == 1)
	{

		//AVEManipulateLed(BIT6,PORTB,LED_ON);

		T1 = AVE_MTIMER0_read();
		TON = (AVE_IcuGetNumberOfOverFlows()*256)+(T1-T0);
		AVE_ClearIcuOverFlows();
		entrant = 0;
		intitalizeExtiRunTimeChange(INT0_EN,EXTI_RISING_EDGE);
		AVEManipulateLed(BIT7,PORTB,LED_OFF);




	}


//	else if(entrant == 1&&flag == 1)
//	{
//
//		flag = 0;
//				entrant = 0;
//				T0 = AVE_MTIMER0_read();
//				TOFF = (AVE_IcuGetNumberOfOverFlows()*256)+(T0-T1);
//				AVE_ClearIcuOverFlows();
////				counts++;
////				if(counts == 2)
////				{
////					AVE_MTIMER0_stop();
////					counts = 0;
////
////				}
//		intitalizeExtiRunTimeChange(EXTI_INT0,EXTI_FALLING_EDGE);
//
//
//
//
//
//
//	}



}


 STATUS  SwICU_Init(uint8 timerNumber)
{

	intitalizeExtiRunTimeChange(INT0_EN,EXTI_RISING_EDGE);
	addExtiCallBackFunction(INT0_EN,startCalculationIcu);
	enableOrDisable(INT0_EN);

	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);






	switch(timerNumber)
	{

	case ICU_TIMER0:
		timerPostCfgStruct.linkingType = PRELINKING;

		AVE_MTIMER0_Initialize(&timerPostCfgStruct);
		AVE_MTIMER0_ICU();





		break;




	}
	return E_OK;
}

void SwICU_Read(uint32*Reading_value)
{

	//return (((f32)(TON)/(TON+TOFF)));
	*Reading_value= TON;

}

