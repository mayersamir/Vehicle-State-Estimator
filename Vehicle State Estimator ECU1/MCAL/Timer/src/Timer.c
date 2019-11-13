/*
 * MTIMER0_SRC.c
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#include "../../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "../../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"


#include "../../../INTERRUPT.h"
#include "TimerLcfg.h"
#include "Timer.h"
#include "TimerCfg.h"

#include "TimerPrivate.h"



static volatile uint8 prescalerValue ;

//void __vector_9(void)__attribute__((signal,INTR_ATTRS));

static void (*TIMER0_ptOverFlowCallBackFunction)(void);

static volatile uint32 numberOfOverFlows;

static volatile uint32 TIMER0_preservedNumberOfOverflows;

static uint32 TIMER0_OCRValue;

static void (*ptToPwmFunction)(void);


















/*
 *
 * Timer1 variables declaration
 */
static uint8 TIMER1_prescalerValue;

static uint16 TIMER1_OCRValue;

static void (*MTIMER1_ptToPwmFunction)(void);


/*
 *
 * declaring a variable to carry the number of needed overflows
 * in order for the timer interrupt ISR to work correctly
 * and declaring other variable that will be manipulated at the
 * ISR function which will be decreased each time the ISR of TIMER1
 * is called that is why they are volatile .
 */
static volatile uint32 TIMER1_numberOfOverFlows;

static volatile uint32 TIMER1_preservedNumberOfOverFlows;

static void (*TIMER1_ptOverFlowCallBackFunction)(void);


/*
 *
 *
 * TIMER2 Variables declaration
 *
 *
 */


//prescaler variable to set the value of the prescaler when intializing
//not to make the timer start after the intializing

static uint16 TIMER2_prescalerValue;



//this pointer to function is for passing a function that will be called
//pwm function from the main function this gave us the luxury not to call
//the dio library inside the timer library !.
void (*MTIMER2_ptToPwmFunction)(void);


static uint16 TIMER2OcrValue;


/*
 *
 * declaring 2 volatile variables for manipulating them inside the ISR implementation
 * numberOfOverFlows to decrease it inside the isr value till it reaches the zero
 * then call the functionality that you want to be fired whenever the time delay you set
 * is done .
 * and the other to perserve the numberOfOverflows in order to keep repeating the delay
 * time you provided in the delay function .
 */

static volatile uint32 TIMER2_numberOfOverFlows;

static volatile uint32 TIMER2_preservedNumberOfOverFlows;

static void (*TIMER2_ptCallBackFunction)(void);

static volatile uint32 IMER0IcuOverFlows = 0;





/*
 *
 *
 * end of variables declarations used for timer0 , timer1 , timer2
 *
 *
 * start of functions implementation !
 *
 *
 *
 */




static void AVE_timer1SetAny(uint16 value,uint8 registerToBeSet)
{


	switch(registerToBeSet)
	{


	case SET_OCR1A :
		TIMER1_OCR1AH = (uint8)(value>>8);
		TIMER1_OCR1AL = (uint8)(value);
		break;
	case SET_ICR1A:
		TIMER1_ICR1H = (uint8)(value>>8);
		TIMER1_ICR1L = (uint8)(value);
		break;

	}


}



 void AVE_TIMER0_setCallBackForInterrupt(void(*ptf)(void))
{

	TIMER0_ptOverFlowCallBackFunction=ptf;
	return;


}




void AVE_MTIMER0_PWMSetFunction(void (*ptToPwmFunctionPassed)(void))
{

	(ptToPwmFunction) = (ptToPwmFunctionPassed);
}



void AVE_MTIMER0_Initialize(timerCfg*configurationStruct)
{

	//this will be all replaced at the preprocessing time.
	//and it is by default the intializtion of the timer.

prescalerValue = (0x05);

#if MTIMER0_PRECONFIGURED_MODE == MTIMER0_NORMAL
	CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM00);
	CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM01);
#elif MTIMER0_PRECONFIGURED_MODE == MTIMER0_CTC
	SET_BIT(TIMER0_TIMSK,TIMSK_OCIE0);
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
#endif


#if MTIMER0_OPERATION_SETTING == TIMER0_TOIE_NORMAL
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
	SET_BIT(TIMER0_TIMSK,TIMSK_TOIE0);
	//AVE_MTIMER0_set((256-(MTIMER0_COUNT/(maxValueCounter))));
	//AVE_MTIMER0_delay_ms()
	//AVE_MTIMER0_start();
#elif MTIMER0_OPERATION_SETTING == TIMER0_OIE_CTC
	SET_BIT(TIMER0_TIMSK,TIMSK_OCIE0);
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
	AVE_MTIMER0_set((256-(MTIMER0_COUNT/(maxValueCounter))));
	AVE_MTIMER0_start();
#endif







if(((timerCfg*)configurationStruct)->linkingType == POSTLINKING)
{


	switch(((timerCfg*)configurationStruct)->mode)
	{

	case TIMER:
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM00);
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM01);

		break;
//	case MTIMER0_CTC:
//		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM00);
//		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_WGM01);
////		TIMER0_OCRValue = outputCompareValue;
////		TIMER0_OCR0 = outputCompareValue;
//
//		break;
	}

//	switch(configurationStruct->prescalerValue)
//	{
//
//	case MTIMER0_NOPRESCALER:
//		prescalerValue = (0x01);
//		break;
//	case MTIMER0_PRESCALER8:
//		prescalerValue = 0x02;
//		break;
//	case MTIMER0_PRESCALER64:
//		prescalerValue = (0x03);
//		break;
//	case MTIMER0_PRESCALER256:
//		prescalerValue = (0x04);
//		break;
//	case MTIMER0_PRESCALER1024:
//		prescalerValue = (0x05);
//		break;
//
//	}

	switch(((timerCfg*)configurationStruct)->interruptMode)
	{

	case TIMER0_OIE_CTC:
		SET_BIT(TIMER0_TIMSK,TIMSK_OCIE0);
		globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
		AVE_MTIMER0_set((256-(MTIMER0_COUNT/(maxValueCounter))));
		AVE_MTIMER0_start();
		break;
	case TIMER0_TOIE_NORMAL:
		globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(TIMER0_TIMSK,TIMSK_TOIE0);
		AVE_MTIMER0_set((256-(MTIMER0_COUNT/(maxValueCounter))));
		AVE_MTIMER0_start();

		break;
	case TIMER0_POLLING:
		break;
	default:
		break;

	}




}



}

void AVE_MTIMER0_start(void)
{
	TIMER0_TCCR0 &= (0xF8);

	TIMER0_TCCR0 |= prescalerValue;


	return;
}

uint8 AVE_MTIMER0_read(void)
{

	return TIMER0_TCNT0;

}

void AVE_MTIMER0_set(uint8 setValue)
{
	TIMER0_TCNT0 = setValue;
}

void AVE_MTIMER0_stop(void)
{

	TIMER0_TCCR0 &= (0xF8);
	TIMER0_TCNT0 = 0;

	return;
}

void AVE_MTIMER0_delay_ms(uint32 delayValue,uint8 interruptValue)
{

	f32 tickTime;

	f32 prescalingValue;
#if MTIMER0_PRESCALER == MTIMER0_PRESCALER8
	prescalingValue = 8;
#elif MTIMER0_PRESCALER == MTIMER0_PRESCALER64
	prescalingValue = 64;
#elif MTIMER0_PRESCALER == MTIMER0_PRESCALER256
	prescalingValue = 256;
#elif MTIMER0_PRESCALER == MTIMER0_PRESCALER1024
	prescalingValue = 1024;
#else
	prescalingValue = 1;
#endif

	tickTime =(f32)(1000000*(prescalingValue/(f32)MTIMER0_SPEED));



	uint32 timeOfOverFlow = 256 * tickTime;
	uint32 numberOfOverflows = ((delayValue*1000)/timeOfOverFlow);
	uint16 preLoad = 256-((delayValue*1000)%timeOfOverFlow);

	if(preLoad<256)
	{
		TIMER0_TCNT0 = preLoad;
		numberOfOverflows++;

	}
	TIMER0_preservedNumberOfOverflows =numberOfOverFlows=numberOfOverflows;




//#if MTIMER0_OPERATION_SETTING == MTIMER0_POLLING

	AVE_MTIMER0_start();

	switch(interruptValue)
	{

	case TIMER0_POLLING:

	while(numberOfOverflows)
		{

			if(((TIMER0_TIFR)&(1<<TIMER0_TIFR_TOV0))==1)
			{
				numberOfOverflows--;
				SET_BIT(TIMER0_TIFR,TIMER0_TIFR_TOV0);

			}
		}
		break;
	case TIMER0_TOIE_NORMAL:
		break;



	}

}




void AVE_updateIcuNumberOfOverFlows(void)
{

	IMER0IcuOverFlows++;

	//AVE_MTIMER0_stop();


}




void AVE_MTIMER0_ICU(void)
{
	AVE_TIMER0_setCallBackForInterrupt(AVE_updateIcuNumberOfOverFlows);
	numberOfOverFlows = TIMER0_preservedNumberOfOverflows = 0;
	AVE_MTIMER0_start();






}




uint32 AVE_IcuGetNumberOfOverFlows(void)
{

	return IMER0IcuOverFlows;

}

void AVE_ClearIcuOverFlows(void)
{
	IMER0IcuOverFlows = 0;

}

static uint16 AVE_timer0SetPrescalerValue(void)
{
	uint16 prescalerReturnedValue;
	if(prescalerValue == (0x01))
	{
		prescalerReturnedValue = 1;

	}
	else if(prescalerValue==(0x02))
	{
		prescalerReturnedValue = 8;

	}
	else if(prescalerValue==(0x03))
	{
		prescalerReturnedValue = 64;
	}
	else if(prescalerValue == (0x04))
	{
		prescalerReturnedValue = 256;

	}
	else
	{
		prescalerReturnedValue = 1024;
	}

	return prescalerReturnedValue;
}


void AVE_TIMER0_CTC_delay_ms(uint32 delayValue,uint8 ocr0State)
{


	switch(ocr0State)
	{

	case TIMER0_OCR_DISCONNECTED:
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_COM00);
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_COM01);
		break;
	case TIMER0_OCR_SET:
		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_COM00);
		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_COM01);
		break;
	case TIMER0_OCR_CLEAR:
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_COM00);
		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_COM01);
		break;
	case TIMER0_OCR_TOGGLE:
		SET_BIT(TIMER0_TCCR0,TIMER0_TCCR0_COM00);
		CLEAR_BIT(TIMER0_TCCR0,TIMER0_TCCR0_COM01);
		break;


	}

	uint32 prescalerValue = AVE_timer0SetPrescalerValue();

	f32 tickTime =(f32)(1000000*(prescalerValue/(f32)MTIMER0_SPEED));



	uint32 timeOfOverFlow = (TIMER0_OCRValue+1) * tickTime;
	uint32 numberOfOverflows = ((delayValue*1000)/timeOfOverFlow);
	uint16 preLoad = (TIMER0_OCRValue+1)-((delayValue*1000)%timeOfOverFlow);




	if(preLoad<(TIMER0_OCRValue+1))
	{
		TIMER0_TCNT0 = preLoad;
		numberOfOverflows++;

	}
	TIMER0_preservedNumberOfOverflows = numberOfOverflows;





	AVE_MTIMER0_start();

	while(numberOfOverflows)
	{

		if(((TIMER0_TIFR)&(1<<TIMER0_TIFR_TOV0))==1)
		{
			numberOfOverflows--;
			SET_BIT(TIMER0_TIFR,TIMER0_TIFR_TOV0);

		}
	}


	AVE_MTIMER0_stop();
}



/*
 *
 * this function is for the application to call it to set the callback function that
 * will be used by the pulse width modulation function for timer2
 */




void AVE_timer0SwPWM(uint8 dutyCycle)
{
	uint16 T = (1000/1);

	uint16 TON = (dutyCycle*T)/100 ;

	uint16 TOFF = T-TON;
	(ptToPwmFunction)();
	AVE_MTIMER0_delay_ms(TON,TIMER0_POLLING);
	(ptToPwmFunction)();
	AVE_MTIMER0_delay_ms(TOFF,TIMER0_POLLING);






}




ISR(INT10_TIMER0_OVF)
{


	if(numberOfOverFlows!=0)
	{
		numberOfOverFlows--;
	}
	else
	{
		numberOfOverFlows = TIMER0_preservedNumberOfOverflows;
		TIMER0_ptOverFlowCallBackFunction();

	}

}
















/*
 *
 *
 *
 *
 * TIMER1 functions Implementation
 */



/*
 *
 *
 * mode variable takes in one of the predefined modes inside the interface file
 *
 * prescaler takes in any of the prescalers of the timer1 available prescalers
 *
 * intialvalue takes in any value that you want the timer counter to start with
 *
 * outputCompareValue takes in any value that you want the outputcompare register to get filled
 * with but note you got to choose the mode of CTC in order for that to work else pass zero
 *
 *
 */

void AVE_timer1Init(timerCfg*configuration)//uint8 mode,uint8 prescaler, uint16 initialValue, uint16 outputCompareValue,uint16 inputCapture, uint8 interruptMask)
{




#if MTIMER1_PRECONFIGURED_MODE == TIMER1_PHASE_ICR1
	CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_WGM01);
	SET_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
	CLEAR_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
	SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
	CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
#elif MTIMER1_PRECONFIGURED_MODE == TIMER1_NORMALMODE:
	CLEAR_BIT(TIMER1_TCCR1A,0);
	CLEAR_BIT(TIMER1_TCCR1A,1);
	CLEAR_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
	CLEAR_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
#endif

#if MTIMER1_PRESCALER == TIMER1_NOPRESCALER
	TIMER1_prescalerValue = (0x01);
#elif MTIMER1_PRESCALER == TIMER1_PRESCALER8
	TIMER1_prescalerValue = (0x02);
#elif MTIMER1_PRESCALER == TIMER1_PRESCALER64
	TIMER1_prescalerValue = (0x03);
#elif MTIMER1_PRESCALER == TIMER1_PRESCALER256
	TIMER1_prescalerValue = (0x04);
#elif MTIMER1_PRESCALER == TIMER1_PRESCALER1024
	TIMER1_prescalerValue = (0x05);
#else
#endif


#if MTIMER1_OPERATION_SETTING == TIMER1_POLLING

#elif MTIMER1_OPERATION_SETTING == TIMER1_TOIE_OVF
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
	SET_BIT(TIMER1_TIMSK,TIMSK_TOIE1);
#elif MTIMER1_OPERATION_SETTING == TIMER1_OCIE1B_CTC
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
	SET_BIT(TIMER1_TIMSK,TIMSK_OCIE1B);
#elif MTIMER1_OPERATION_SETTING == TIMER1_OCIE1A_CTC
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
	SET_BIT(TIMER1_TIMSK,TIMSK_OCIE1A);
#elif MTIMER1_OPERATION_SETTING == TIMER1_TICIE1_ICU
	globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
	SET_BIT(TIMER1_TIMSK,TIMSK_TICIE1);
#else
#endif










	//uint16 valueToBeSet = outputCompareLow;


	if(configuration->linkingType == POSTLINKING)
	{

	switch(configuration->mode)
	{


	case TIMER1_NORMALMODE:
		CLEAR_BIT(TIMER1_TCCR1A,0);
		CLEAR_BIT(TIMER1_TCCR1A,1);
		CLEAR_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
		CLEAR_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
		break;

	case TIMER1_CTC_OCR1A:
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_WGM01);
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
		SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
		CLEAR_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
		//AVE_timer1SetAny(outputCompareValue,SET_OCR1A);
		//TIMER1_OCRValue = outputCompareValue;
		break;
	case TIMER1_CTC_ICR1A:
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_WGM01);
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
		SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
		SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
		break;
	case TIMER1_PHASE_ICR1:
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_WGM01);
		SET_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
		CLEAR_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
		SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
		break;

//	case TIMER1_SET_CTC:
//		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_WGM01);
//		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
//		SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
//		CLEAR_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
//		break;




	}
	switch(configuration->mode)
	{

	case TIMER1_NOPRESCALER:
		TIMER1_prescalerValue = (0x01);
		break;
	case TIMER1_PRESCALER8:
		TIMER1_prescalerValue = (0x02);
		break;
	case TIMER1_PRESCALER64:
		TIMER1_prescalerValue = (0x03);
		break;
	case TIMER1_PRESCALER256:
		TIMER1_prescalerValue = (0x04);
		break;
	case TIMER1_PRESCALER1024:
		TIMER1_prescalerValue = (0x05);
		break;

	}


	switch(configuration->interruptMode)
	{

	case TIMER1_TOIE_OVF:
		globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(TIMER1_TIMSK,TIMSK_TOIE1);
		break;
	case TIMER1_OCIE1B_CTC:
		globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(TIMER1_TIMSK,TIMSK_OCIE1B);
		break;
	case TIMER1_OCIE1A_CTC:
		globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(TIMER1_TIMSK,TIMSK_OCIE1A);
		break;
	case TIMER1_TICIE1_ICU:
		globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(TIMER1_TIMSK,TIMSK_TICIE1);
		break;
	case TIMER1_POLLING:
		break;

	}


	}


}


void Ave_timer1PWM(uint8 dutyCycle,uint16 freq){

	uint16 prescaler1 = 1024;
	uint32 top;
	//Prescalervar1();
	top=((8000000UL)/(freq*2*prescaler1));
	TIMER1_ICR1L_16=top;
	TIMER1_OCR1AL_16=(((uint32)dutyCycle*top)/100);
	AVE_timer1Start();
}



void AVE_timer1Start(void)
{


	TIMER1_TCCR1B &= (0xF8);//for clearing the three bits of the register that is responsible
	                        //setting the prescaler value to be able to set the new prescaler value correctly.
	TIMER1_TCCR1B |= TIMER1_prescalerValue;

	return ;
}


void AVE_timer1Stop(void)
{
	TIMER1_TCCR1B &= (0xF8);//clearing the prescaler value for the timer to stop
	TIMER1_TCNT1H = 0;//setting the counter value of the timer to be zero
					//in order for the timer to work correctly next time the
				//Timer start is called .
	TIMER1_TCNT1L = 0;

	return ;
}


/*
 *
 *
 * this function is responsible for setting the counter value of timer1.
 *
 * for the user if he wants to start the timer by default with a specific value in it .
 *
 */
void AVE_timer1Set(uint16 value)
{

	TIMER1_TCNT1H = (uint8)(value>>8);
	TIMER1_TCNT1L = (uint8)value;

	return ;

}


/*
 * this function is responsible for getting the value of the timer counter
 *
 * that is why it is static for being used only here
 *
 *
 *
 */
//static uint16 AVE_timer1Get(uint8 registerToBeSet)
//{
//
//	uint16 TCNT1Value;
//
//	TCNT1Value = TIMER1_TCNT1L;
//	TCNT1Value = (TIMER1_TCNT1H<<8);
//	return TCNT1Value;
//}


/*
 *
 *
 *
 * this function is for mapping the prescaler register value into
 * its divider value .
 *
 * so you can see that (0x02) the value of the register is mapped into 8 which is the divider
 * value for the time .
 */


static uint16 AVE_TIMER1_setPreScalerValue(void)
{


	uint16 prescalerValue;

		if(TIMER1_prescalerValue==(0x01))
		{

			prescalerValue = 1;
		}
		else if(TIMER1_prescalerValue==(0x02))
		{
			prescalerValue = 8;
		}
		else if(TIMER1_prescalerValue==(0x03))
		{
			prescalerValue = 64;
		}
		else if(TIMER1_prescalerValue==(0x04))
		{
			prescalerValue = 256;
		}
		else
		{
			prescalerValue = 1024;
		}

		return prescalerValue;



}

void AVE_TIMER1_delayMs(uint32 delayValue,uint8 interruptMode)
{
	uint32 prescalerValue = AVE_TIMER1_setPreScalerValue();
//
//	if(TIMER1_prescalerValue==(0x01))
//	{
//
//		prescalerValue = 1;
//	}
//	else if(TIMER1_prescalerValue==(0x02))
//	{
//		prescalerValue = 8;
//	}
//	else if(TIMER1_prescalerValue==(0x03))
//	{
//		prescalerValue = 64;
//	}
//	else if(TIMER1_prescalerValue==(0x04))
//	{
//		prescalerValue = 256;
//	}
//	else
//	{
//		prescalerValue = 1024;
//	}


	/*
	 *
	 * setting the prescalerValue to use it in the equation of calculating the
	 * delay needed
	 */

	f32 tickTime = ((f32)prescalerValue/(f32)MC_FREQUENCY);

	uint32 timeOfOverFlow = 65536*tickTime;

	uint32 numberOfOverFlows = (delayValue*1000)/timeOfOverFlow;

	uint32 preload =65536-(delayValue*1000)%timeOfOverFlow;



	if(preload<65536)
	{

		AVE_timer1Set(preload);
		numberOfOverFlows++;

	}
	TIMER1_numberOfOverFlows = TIMER1_preservedNumberOfOverFlows = numberOfOverFlows;

	AVE_timer1Start();
	//if(numberOfOverFlows != 0)
	//{

	switch(interruptMode)
	{

	case TIMER1_POLLING:
		while(numberOfOverFlows != 0)
			{


				while(!(TIMER1_TIFR&(1<<TIFR_TOV1)));


					numberOfOverFlows--;
					TIMER1_TIFR |= (1<<TIFR_TOV1);




			}
		AVE_timer1Stop();

		break;

	}




//
	//}
	//else
	//{

//		uint16 compareValue;
//
//
//		while(compareValue <= preload )
//		{
//			compareValue=AVE_timer1Get();
//		}
//
//
//
//
//	}



	return;


}


/*
 *
 * implementing a function to get a pointer to a function that take a void
 * and returns a void from the main application
 * in order to call that function everytimer an overflow for the timer1 happens
 * logically that function which will be implemented at the main application
 * will access the DIO that is why i haven't implemented here in the timer.c
 * file for the library of the timer to be independent of any other library !
 *
 */
void AVE_setCallBackFunction(void(*ptf)(void))
{

	TIMER1_ptOverFlowCallBackFunction = ptf;
}



ISR(INT8_TIMER1_OVF)
{


	if(TIMER1_numberOfOverFlows!=0)
	{
		TIMER1_numberOfOverFlows--;
	}
	else
	{
		TIMER1_numberOfOverFlows = TIMER1_preservedNumberOfOverFlows;
		TIMER1_ptOverFlowCallBackFunction();

	}

}


void AVE_TIMER1_CTC_delay_ms(uint32 delayValue,uint8 ocPinMode)
{


	switch(ocPinMode)
	{


	case TIMER1_CTC_DISABLE:
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
		break;
	case TIMER1_CTC_SET:
		SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
		SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
		break;
	case TIMER1_CTC_CLEAR:
		SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
		break;
	case TIMER1_CTC_TOGGLE:
		CLEAR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
		SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
		break;
	}


	uint32 prescaleValue = AVE_TIMER1_setPreScalerValue();
	//AVE_timer1SetAny(65535,SET_OCR1A);

	f32 tickTime = ((f32)prescaleValue/(f32)MC_FREQUENCY);

	uint32 timeOfOverFlow = (TIMER1_OCRValue+1)*tickTime;

	uint32 numberOfOverFlows = (delayValue*1000)/timeOfOverFlow;

	uint32 preload =(TIMER1_OCRValue+1)-(delayValue*1000)%timeOfOverFlow;




	if(preload<(TIMER1_OCRValue+1))
	{

		AVE_timer1Set(preload);
		numberOfOverFlows++;

	}

	AVE_timer1Start();


		while(numberOfOverFlows != 0)
		{

			while(!(TIMER1_TIFR&(1<<TIFR_OCF1A)));

				numberOfOverFlows--;
				TIMER1_TIFR |= (1<<TIFR_OCF1A);



		}


		AVE_timer1Stop();

	return;





}



/*
 *
 *
 * i have mad a workaround not to make the MTIMER1 call DIO library directly
 * for pwm to work and being tested it must use the DIO so that i made a pointer to function
 * and i call it at the sw_pwm function for timer1
 *
 * and i have made a public function to set that pointer to function in order for that function
 * being called at the main
 *
 * what i got from that ?
 *
 * i got that i had every module is independent of any other module
 *
 * and the main is responsible for calling anything .
 */

void AVE_MTIMER1_setCallBackPwm(void(*ptf)(void))
{


	MTIMER1_ptToPwmFunction = ptf;

}




void AVE_MTIMER1_swPwm(uint32 frequency,uint8 dutyCycle)
{


	uint16 T = (1000/frequency);

	uint16 TON = (dutyCycle*T)/100 ;

	uint16 TOFF = T-TON;
	(MTIMER1_ptToPwmFunction)();
	AVE_TIMER1_delayMs(TON,TIMER1_POLLING);
	(MTIMER1_ptToPwmFunction)();
	AVE_TIMER1_delayMs(TOFF,TIMER1_POLLING);




	return ;

}









/*
 *
 *
 *
 *
 * TIMER2 functions implementation . !!
 *
 *
 */


/*
 *
 * implementing a function to set value of TIMER2 registers
 * specially made for the ctc mode
 * to make the limit is OCR register or ICR register !
 */


static void AVE_setValueForCTC(uint8 registerName,uint8 value)
{

	switch(registerName)
	{
	case TIMER2_SET_OCR:
		TIMER2_OCR2 = value;
		break;
//	case TIMER2_SET_ICR:
//		TIMER2_ = value;
//		break;
	}


}



void AVE_timer2Init(uint8 mode,uint8 prescaler, uint8 initialValue, uint8 outputCompare, uint8 assynchronous, uint8 interruptMask)
{

	/*
	 * setting the operating mode of the TIMER2
	 */

	switch(mode)
	{

	case TIMER2_NORMAL_MODE:
		CLEAR_BIT(TIMER2_TCCR2,TCCR2_WGM20);
		CLEAR_BIT(TIMER2_TCCR2,TCCR2_WGM21);
		break;
	case TIMER2_CTC:
		CLEAR_BIT(TIMER2_TCCR2,TCCR2_WGM20);
		SET_BIT(TIMER2_TCCR2,TCCR2_WGM21);
		TIMER2OcrValue = outputCompare;
		AVE_setValueForCTC(TIMER2_SET_OCR,outputCompare);

		break;
	case TIMER2_PWM_FAST:
		SET_BIT(TIMER2_TCCR2,TCCR2_WGM20);
		SET_BIT(TIMER2_TCCR2,TCCR2_WGM21);
		break;
	case TIMER2_PWM_PHASECORRECT:
		SET_BIT(TIMER2_TCCR2,TCCR2_WGM20);
		CLEAR_BIT(TIMER2_TCCR2,TCCR2_WGM21);
		break;

	}
	/*
	 *
	 *
	 * setting the operating division factor for the clk
	 * which is called the prescaler ! .
	 */

	switch(prescaler)
	{
	case TIMER2_NOPRESCALER:
		TIMER2_prescalerValue = (0x01);
		break;
	case TIMER2_PRESCALER8:
		TIMER2_prescalerValue = (0x02);
		break;
	case TIMER2_PRESCALER32:
		TIMER2_prescalerValue = (0x03);
		break;
	case TIMER2_PRESCALER64:
		TIMER2_prescalerValue = (0x04);
		break;
	case TIMER2_PRESCALER128:
		TIMER2_prescalerValue = (0x05);
		break;
	case TIMER2_PRESCALER256:
		TIMER2_prescalerValue = (0x06);
		break;
	case TIMER2_PRESCALER1024:
		TIMER2_prescalerValue = (0x07);
		break;

	}

	/*
	 *
	 * setting the configuration of timer2 to see whether you are going to use
	 * the internal cpu clk
	 * or you are going to put an external clk to be used . !
	 */

	switch(assynchronous)
	{

	case TIMER2_INTERNAL_CLK:
		CLEAR_BIT(TIMER2_ASSR,ASSR_AS2);
		break;
	case TIMER2_EXTERNAL_CLK:
		SET_BIT(TIMER2_ASSR,ASSR_AS2);
		break;

	}

	/*
	 *
	 * setting the interrupt modes for timer2
	 */

	switch(interruptMask)
	{

	case TIMER2_TOIE2_OVF:
		globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(TIMER2_TIMSK,TIMSK_TOIE2);
		break;
	case TIMER2_OCIE2_CTC:
		globalInterruptManipulate(GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(TIMER2_TIMSK,TIMSK_OCIE2);
		break;
	case TIMER2_POLLING:
		break;

	}

}


/*
 *
 *
 * implementing a new function for timer2 for making timer2 delay in ms
 *
 */




/*
 *
 * this special static function i am going to use to map the prescaler previousl
 * set value from the intialize function into a solid hardcoded division factor
 * of the previously chosen prescaler and i could have put the code inside the delay
 * function but i didn't cause that will imply that i will write the same code to make any
 * other function.
 * so that i made a function and put that piece of code that i am going to use in
 * not to make copy and paste !!
 *
 * and since i don't want the user to use this function at the application layer , that is why
 * i made it static !
 */

static uint16 AVE_TIMER2_mapPrescaler(void)
{
	uint16 prescalerValue;

	if(TIMER2_prescalerValue == (0x01))
	{
		prescalerValue = 1;
	}
	else if(TIMER2_prescalerValue == (0x02))
	{
		prescalerValue = 8;
	}
	else if(TIMER2_prescalerValue == (0x03))
	{
		prescalerValue = 32;

	}
	else if(TIMER2_prescalerValue == (0x04))
	{
		prescalerValue = 64;

	}
	else if(TIMER2_prescalerValue == (0x05))
	{
		prescalerValue = 256;
	}
	else
	{
		prescalerValue = 1024;
	}


	return prescalerValue;

}


/*
 *
 * implementing a function to set the value of the previously set prescaler
 * to start timer2
 * that is why i couldn't put the value of the prescaler directly inside the
 * register !
 */

void AVE_TIMER2_start(void)
{
	TIMER2_TCCR2 &= (0xF8);
	TIMER2_TCCR2 |= TIMER2_prescalerValue;
	return;
}


/*
 *
 * this function takes in a paramater which is the value you want to load TIMER2 with
 *
 *
 */

void AVE_TIMER2_set(uint8 value)
{
	TIMER2_TCNT2 = value;
	return;
}

/*
 *
 *
 * implementing a function to put a zero inside the three bits of the control register
 * of the timer in order to make it stop
 *
 */

void AVE_TIMER2_stop(void)
{

	TIMER2_TCCR2 &= (0xF8);
	AVE_TIMER2_set(0);
	return;
}


void AVE_TIMER2_callBackFunctionSet(void(*ptf)(void))
{

	TIMER2_ptCallBackFunction = ptf;
}


/*
 *
 *
 * implementing function to perform the delay functionality using timer2 !
 *
 *
 */



void AVE_TIMER2_delay_ms(uint32 delayValue,uint8 interruptMode)
{

	uint32 prescalerUsedValue = AVE_TIMER2_mapPrescaler();

	f32 tickTime = ((f32)prescalerUsedValue/MC_FREQUENCY);

	uint32 timeOfOverFlow = 256*tickTime;

	uint32 numberOfOverFlows = (delayValue*1000)/timeOfOverFlow;

	uint16 preload = 256-((delayValue*1000)%timeOfOverFlow);


	if(preload<256)
	{


		TIMER2_TCNT2 = preload;
		numberOfOverFlows++;
	}




	AVE_TIMER2_start();


	switch(interruptMode)
	{

	case TIMER2_OCIE2_CTC:
	case TIMER2_TOIE2_OVF:
		TIMER2_preservedNumberOfOverFlows = TIMER2_numberOfOverFlows = numberOfOverFlows;
		break;
	case TIMER2_POLLING:
		while(numberOfOverFlows)
			{

				if((TIMER2_TIFR<<TIFR_TOV2))
				{

					numberOfOverFlows--;
					TIMER2_TIFR |= (1<<TIFR_TOV2);
				}
			}


			AVE_TIMER2_stop();

		break;

	}




return;

}

ISR(INT4_TIMER2_OVF)
{


	if(TIMER2_numberOfOverFlows!=0)
	{
		TIMER2_numberOfOverFlows--;
	}
	else
	{
		TIMER2_numberOfOverFlows = TIMER2_preservedNumberOfOverFlows;
		TIMER2_ptCallBackFunction();

	}

}




void AVE_TIMER2_setCallBackFunction(void(*ptf)(void))
{

	TIMER2_ptCallBackFunction = ptf;

	return;
}



void AVE_TIMER2_sw_pwm(uint8 dutyCycle,uint32 frequency)
{


	uint16 T = (1000/frequency);

	uint16 TON = (dutyCycle*T)/100 ;

	uint16 TOFF = T-TON;
	(TIMER2_ptCallBackFunction)();
	AVE_TIMER2_delay_ms(TON,TIMER2_POLLING);
	(TIMER2_ptCallBackFunction)();
	AVE_TIMER2_delay_ms(TOFF,TIMER2_POLLING);



}

void AVE_TIMER2_CTC_delay_ms(uint32 delayValue,uint8 ocPinState)
{



	switch(ocPinState)
	{

	case TIMER2_CTC_OC2_DISCONNECTED:
		CLEAR_BIT(TIMER2_TCCR2,TCCR2_COM20);
		CLEAR_BIT(TIMER2_TCCR2,TCCR2_COM21);
		break;
	case TIMER2_CTC_OC2_TOGGLE:
		SET_BIT(TIMER2_TCCR2,TCCR2_COM20);
		CLEAR_BIT(TIMER2_TCCR2,TCCR2_COM21);
		break;
	case TIMER2_CTC_OC2_SET:
		SET_BIT(TIMER2_TCCR2,TCCR2_COM20);
		SET_BIT(TIMER2_TCCR2,TCCR2_COM21);
		break;
	case TIMER2_CTC_OC2_CLEAR:
		CLEAR_BIT(TIMER2_TCCR2,TCCR2_COM20);
		SET_BIT(TIMER2_TCCR2,TCCR2_COM21);
		break;
	}

	uint32 prescalerUsedValue = AVE_TIMER2_mapPrescaler();

	f32 tickTime = ((f32)prescalerUsedValue/MC_FREQUENCY);

	uint32 timeOfOverFlow = (TIMER2OcrValue+1)*tickTime;

	uint32 numberOfOverFlows = (delayValue*1000)/timeOfOverFlow;

	uint16 preload = (TIMER2OcrValue+1)-((delayValue*1000)%timeOfOverFlow);




	if(preload<(TIMER2OcrValue+1))
	{


		TIMER2_TCNT2 = preload;
		numberOfOverFlows++;
	}

	AVE_TIMER2_start();


	while(numberOfOverFlows)
	{

		if((TIMER2_TIFR<<TIFR_TOV2))
		{

			numberOfOverFlows--;
			TIMER2_TIFR |= (1<<TIFR_TOV2);
		}
	}


	AVE_TIMER2_stop();
}















