/*
 * MTIMER0_Private.h
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_TIMER_INC_TIMERPRIVATE_H_
#define MCAL_TIMER_INC_TIMERPRIVATE_H_



#define        TIMER0_TCCR0           *((volatile uint8 *const)(0x53))

/*
 *
 * TCCR0 defined bits
 */

#define        TIMER0_TCCR0_CS00       0
#define        TIMER0_TCCR0_CS01       1
#define        TIMER0_TCCR0_CS02       2
#define        TIMER0_TCCR0_WGM01      3
#define        TIMER0_TCCR0_COM00      4
#define        TIMER0_TCCR0_COM01      5
#define        TIMER0_TCCR0_WGM00      6
#define        TIMER0_TCCR0_FOC        7


#define        TIMER0_TCNT0            *((volatile uint8 *const)(0x52))


#define        TIMER0_OCR0             *((volatile uint8 *const)(0x5C))

#define        TIMER0_TIMSK            *((volatile uint8 *const)(0x59))
#define        TIMSK_TOIE0             0
#define        TIMSK_OCIE0             1


/*
 *
 * TIMSK defined bits
 * to ease the manipulation later on using functions
 */

#define        TIMER0_TIMSK_TOIE       0
#define        TIMER0_TIMSK_OCIE       0



#define        TIMER0_TIFR             *((volatile uint8 *const)(0x58))


/*
 *
 * TIFR Bits that will be used for Timer0
 */


#define        TIMER0_TIFR_TOV0        0
#define        TIMER0_TIFR_OCF0        1




/*
 * TIMER1 stuff !!!!!!!!!!!!!!!!!!!!!!!!!!!
 *
 *
 */


#define       TIMER1_TCCR1A                   *((volatile uint8 *const)(0x4F))

#define       TCCR1A_WGM01                    0
#define       TCCR1A_WGM11                    1
#define       TCCR1A_FOC1B                    2
#define       TCCR1A_FOC1A                    3
#define       TCCR1A_COM1B0                   4
#define       TCCR1A_COM1B1                   5
#define       TCCR1A_COM1A0                   6
#define       TCCR1A_COM1A1                   7



#define      TIMER1_TCCR1B                     *((volatile uint8 *const)(0x4E))

#define      TCCR1B_CS10                      0
#define      TCCR1B_CS11                      1
#define      TCCR1B_CS12                      2
#define      TCCR1B_WGM12                     3
#define      TCCR1B_WGM13                     4
#define      TCCR1B_ICES                      6
#define      TCCR1B_ICNC1                     7


#define      TIMER1_TCNT1L                     *((volatile uint8 *const)(0x4C))

#define      TIMER1_TCNT1H                     *((volatile uint8 *const)(0x4D))

#define      TIMER1_OCR1AL                     *((volatile uint8 *const)(0x4A))

#define      TIMER1_OCR1AL_16                   *((volatile uint16 *const)(0x4A))
#define      TIMER1_OCR1AH                     *((volatile uint8 *const)(0x4B))

#define      TIMER1_OCR1BL                     *((volatile uint8 *const)(0x48))

#define      TIMER1_OCR1BH                     *((volatile uint8 *const)(0x49))

#define      TIMER1_ICR1L                      *((volatile uint8 *const)(0x46))

#define      TIMER1_ICR1L_16                   *((volatile uint16* const)(0x46))

#define      TIMER1_ICR1H                      *((volatile uint8 *const)(0x47))

#define      TIMER1_TIMSK                      *((volatile uint8 *const)(0x59))
#define      TIMSK_TOIE1                       2
#define      TIMSK_OCIE1B                      3
#define      TIMSK_OCIE1A                      4
#define      TIMSK_TICIE1                      5



#define      TIMER1_TIFR                       *((volatile uint8 *const)(0x58))

#define      TIFR_TOV1                         2
#define      TIFR_OCF1B                        3
#define      TIFR_OCF1A                        4
#define      TIFR_ICF1                         5



#define      SET_OCR1A                         0
#define      SET_ICR1A                         1




/*
 *
 *
 * TIMER2 special registers and their bits defineition
 */


#define TIMER2_TCCR2                            *((reg_type)(0x45))
#define TCCR2_CS20                              0
#define TCCR2_CS21                              1
#define TCCR2_CS22                              2
#define TCCR2_WGM21                             3
#define TCCR2_COM20                             4
#define TCCR2_COM21                             5
#define TCCR2_WGM20                             6
#define TCCR2_FOC2                              7


#define TIMER2_TCNT2                            *((reg_type)(0x44))

#define TIMER2_OCR2                             *((reg_type)(0x43))


#define TIMER2_ASSR                             *((reg_type)(0x42))
#define ASSR_AS2                                3
#define ASSR_TCN2UB                             2
#define ASSR_OCR2UB                             1
#define ASSR_TCR2UB                             0

#define TIMER2_TIMSK                            *((reg_type)(0x59))
#define TIMSK_TOIE2                              6
#define TIMSK_OCIE2                              7


#define TIMER2_TIFR                              *((reg_type)(0x58))
#define TIFR_TOV2                                6
#define TIFR_OCF2                                7


#define TIMER2_SFIOR                             *((reg_type)(0x50))
#define SFIOR_PSR2                               1


#define TIMER2_SET_OCR    0
#define TIMER2_SET_ICR    1


#endif /* MCAL_TIMER_INC_TIMERPRIVATE_H_ */
