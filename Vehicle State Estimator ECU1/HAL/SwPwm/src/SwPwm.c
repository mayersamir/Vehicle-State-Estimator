/*
 * swPWM.c
 *
 *  Created on: Oct 26, 2019
 *      Author: AVE-LAP-070
 */



#include "../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "TimerLcfg.h"
#include "Timer.h"
#include "SwPwm.h"




/*
 *
 * this function is to intialize the pwm timer used
 * and initialize the mode and the prescaler for that timer
 * and passing the function as a pointer to that pwm function
 * to be called every on time and every off time
 */

void sw_PWMIntialize(uint8 swPwmNumber,uint8 timerInterruptMode,uint8 prescalermode,uint16 outputCompareValue)
{

	switch(swPwmNumber)
	{
	case SW_PWM_TIMER0:
		switch(timerInterruptMode)
		{

		case TIMER0_POLLING:
			//AVE_MTIMER0_Initialize(prescalermode,MTIMER0_NORMAL,0,TIMER0_POLLING);
//			AVE_MTIMER0_PWMSetFunction(ptf);
//			AVE_timer0SwPWM(dutyCycle);
			break;
		case TIMER0_TOIE_NORMAL:
			//AVE_MTIMER0_Initialize(prescalermode,MTIMER0_NORMAL,0,TIMER0_TOIE_NORMAL);
//			AVE_MTIMER0_PWMSetFunction(ptf);
//			AVE_timer0SwPWM(dutyCycle);
			break;
		case TIMER0_OIE_CTC:
			//AVE_MTIMER0_Initialize(prescalermode,MTIMER0_CTC,outputCompareValue,TIMER0_OIE_CTC);
//			AVE_MTIMER0_PWMSetFunction(ptf);
//			AVE_timer0SwPWM(dutyCycle);
			break;



		}

		break;

	case SW_PWM_TIMER1:
		switch(timerInterruptMode)
		{
		case TIMER1_POLLING:
			//AVE_timer1Init(TIMER1_NORMALMODE,prescalermode,0,0,0,TIMER1_POLLING);
//			AVE_MTIMER1_setCallBackPwm(ptf);
//			AVE_MTIMER1_swPwm(frequency,dutyCycle);
			break;
		case TIMER1_TOIE_OVF:
			//AVE_timer1Init(TIMER1_NORMALMODE,prescalermode,0,0,0,TIMER1_TOIE_OVF);
//			AVE_MTIMER1_setCallBackPwm(ptf);
//			AVE_MTIMER1_swPwm(frequency,dutyCycle);
			break;

		}
		break;

	case SW_PWM_TIMER2:
		switch(timerInterruptMode)
		{

		case TIMER2_POLLING:
			AVE_timer2Init(TIMER2_NORMAL_MODE,prescalermode,0,0,TIMER2_INTERNAL_CLK,TIMER2_POLLING);
//			AVE_TIMER2_setCallBackFunction(ptf);
//			AVE_TIMER2_sw_pwm(dutyCycle,frequency);
			break;

		}


	}

}


/*
 *
 *it selects which pulse width modulation for what timer to work !
 *it
 */

void sw_PWMSelect(uint8 swPwmNumber,uint8 dutyCycle,uint16 frequency,void(*ptf)(void))
{

	switch(swPwmNumber)
	{
	case SW_PWM_TIMER0:
		AVE_MTIMER0_PWMSetFunction(ptf);
		AVE_timer0SwPWM(dutyCycle);
		break;
	case SW_PWM_TIMER1:
		AVE_MTIMER1_setCallBackPwm(ptf);
		AVE_MTIMER1_swPwm(frequency,dutyCycle);
		break;
	case SW_PWM_TIMER2:
		AVE_TIMER2_callBackFunctionSet(ptf);
		AVE_TIMER2_sw_pwm(dutyCycle,frequency);
		break;


	}
}
