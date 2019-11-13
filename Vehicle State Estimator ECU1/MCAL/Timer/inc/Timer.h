/*
 * MTIMER0_Interface.h
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_TIMER_INC_TIMER_H_
#define MCAL_TIMER_INC_TIMER_H_



/**
 *
 *
 * defining the microcontroller frequency to ease the use of timers
 *
 * write the frequency as a unit of MHZ mega hertz like 16 it means
 *
 * 16 MHZ
 */

#define MC_FREQUENCY     8


/*
 *
 *
 * defining Timer0 available modes
 */


#define MTIMER0_NORMAL            0
#define MTIMER0_PWM_PHASECORRECT  1
#define MTIMER0_CTC               2
#define MTIMER0_PWM_FAST          3


/*
 *
 * Timer0 prescaler settings
 */

#define MTIMER0_NOPRESCALER        0
#define MTIMER0_PRESCALER8         1
#define MTIMER0_PRESCALER64        2
#define MTIMER0_PRESCALER256       3
#define MTIMER0_PRESCALER1024      4

/*
 *
 * MTIMER0 operation modes
 */

#define MTIMER0_POLLING            0

#define MTIMER0_PWM_FREQ           2UL


/*defining the ocr0 states when choosing the CTC mode as the
 * operating mode for timer 0
 */

#define TIMER0_OCR_DISCONNECTED    0
#define TIMER0_OCR_SET             1
#define TIMER0_OCR_CLEAR           2
#define TIMER0_OCR_TOGGLE          3



#define TIMER  0
#define COUNTER 1


#define maxValueCounter 64
/*
 *
 *
 *
 * timer0 interrupts modes of operations !!
 */

#define   TIMER0_OIE_CTC            0
#define   TIMER0_TOIE_NORMAL        1
#define   TIMER0_POLLING            2



void AVE_MTIMER0_Initialize(timerCfg*configurationStruct);

void AVE_MTIMER0_stop(void);

void AVE_MTIMER0_delay_ms(uint32 delayValue,uint8 interruptValue);

void AVE_timer0SwPWM(uint8 dutyCycle);

void AVE_MTIMER0_start(void);

uint8 AVE_MTIMER0_read(void);

void AVE_MTIMER0_PWMSetFunction(void (*ptToPwmFunctionPassed)(void));

void AVE_MTIMER0_set(uint8 setValue);


void AVE_TIMER0_setCallBackForInterrupt(void(*ptf)(void));


void AVE_MTIMER0_ICU(void);

uint32 AVE_IcuGetNumberOfOverFlows(void);

void AVE_ClearIcuOverFlows(void);





/*
 *
 * TIMER1 functions
 */


#define TIMER1_NORMALMODE  0

#define TIMER1_CTC_OCR1A   1

#define TIMER1_CTC_ICR1A   2

#define TIMER1_PHASE_ICR1  3


//#define TIMER1_SET_CTC     3





/*
 *
 *
 * oc pint for clear to compare mode in timer1 !
 */


#define TIMER1_CTC_SET       0

#define TIMER1_CTC_CLEAR     1

#define TIMER1_CTC_TOGGLE    2

#define TIMER1_CTC_DISABLE   3



/*
 *
 * definition of prescalers
 *
 */

#define TIMER1_NOPRESCALER  0
#define TIMER1_PRESCALER1   1
#define TIMER1_PRESCALER8   2
#define TIMER1_PRESCALER64  3
#define TIMER1_PRESCALER256 4
#define TIMER1_PRESCALER1024 5


/*
 *
 * INTERRUPTS modes for TIMER1
 */

#define TIMER1_TOIE_OVF    0
#define TIMER1_OCIE1B_CTC  1
#define TIMER1_OCIE1A_CTC  2
#define TIMER1_TICIE1_ICU  3
#define TIMER1_POLLING     4




//void AVE_timer1Init(uint8 mode,uint8 prescaler, uint16 initialValue,uint16 outputCompareValue,uint16 inputCapture, uint8 interruptMask);

void AVE_timer1Init(timerCfg*configuration);

void AVE_timer1Start(void);


void AVE_timer1Stop(void);


void AVE_timer1Set(uint16 value);


void AVE_TIMER1_delayMs(uint32 delayValue,uint8 interruptMode);


void AVE_TIMER1_CTC_delay_ms(uint32 delayValue,uint8 ocPinMode);


void AVE_MTIMER1_setCallBackPwm(void(*ptf)(void));



void AVE_MTIMER1_swPwm(uint32 frequency,uint8 dutyCycle);

void AVE_setCallBackFunction(void(*ptf)(void));

void Ave_timer1PWM(uint8 dutyCycle,uint16 freq);

/*
 *
 *
 * TIMER2 stuff that will include the functions header and its mode definitions !
 *
 *
 */


//TIMER2 modes

#define TIMER2_NORMAL_MODE      0

#define TIMER2_PWM_PHASECORRECT 1

#define TIMER2_PWM_FAST         2

#define TIMER2_CTC              3


/*
 *
 * definition of what happens to OC2 pin whenever you choose the ctc mode
 * to be the operation mode for Timer2
 *
 *
 *
 */


#define TIMER2_CTC_OC2_SET         0
#define TIMER2_CTC_OC2_CLEAR       1
#define TIMER2_CTC_OC2_TOGGLE      2
#define TIMER2_CTC_OC2_DISCONNECTED 3




/*
 *
 *
 * the defintion of the timer2 prescalers
 *
 *
 */

#define TIMER2_NOPRESCALER          0
#define TIMER2_PRESCALER8           1
#define TIMER2_PRESCALER32          2
#define TIMER2_PRESCALER64          3
#define TIMER2_PRESCALER128         4
#define TIMER2_PRESCALER256         5
#define TIMER2_PRESCALER1024        6



/*
 * TIMER2 Interrupt modes that are available
 */


#define TIMER2_TOIE2_OVF            0
#define TIMER2_OCIE2_CTC            1
#define TIMER2_POLLING              2



/*
 *
 *
 * defintion of clock source of TIMER2 whether
 * is it going to work on external clock source
 * or it will work using the internal cpu clock
 * source !!!!..
 */

#define TIMER2_INTERNAL_CLK         0
#define TIMER2_EXTERNAL_CLK         1



void AVE_timer2Init(uint8 mode,uint8 prescaler, uint8 initialValue, uint8 outputCompare, uint8 assynchronous, uint8 interruptMask);

void AVE_TIMER2_start(void);

void AVE_TIMER2_set(uint8 value);

void AVE_TIMER2_stop(void);

void AVE_TIMER2_delay_ms(uint32 delayValue,uint8 interruptMode);

void AVE_TIMER2_setCallBackFunction(void(*ptf)(void));


void AVE_TIMER2_sw_pwm(uint8 dutyCycle,uint32 frequency);


void AVE_TIMER2_CTC_delay_ms(uint32 delayValue,uint8 ocPinState);


void AVE_TIMER2_callBackFunctionSet(void(*ptf)(void));


#endif /* MCAL_TIMER_INC_TIMER_H_ */
