/*
 * INTERRUPT.h
 *
 *  Created on: Oct 25, 2019
 *      Author: AVE-LAP-070
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define _vector(N)                     __vector_##N




/*
 * exteranl interrupt zero
 */
#define INTO_EXTI0                     _vector(1)

/*
 * external interrupt one
 */
#define INT1_EXTI1                     _vector(2)

/*
 * external interrupt two
 */
#define INT2_EXTI2                     _vector(3)

/*
 * timer2 compare match happened
 */
#define INT3_TIMER2_CMP                _vector(4)

/*
 * timer2 overflow happened
 */
#define INT4_TIMER2_OVF                _vector(5)

/*
 * TIMER1 input capture unit happened
 */
#define INT5_TIMER1_CAPT               _vector(6)

/*
 * TIMER1 compare match for channel A happened
 */
#define INT6_TIMER1_COMPA              _vector(7)

/*
 * timer1 compare match for channel B happened
 */
#define INT7_TIMER1_COMPB              _vector(8)

/*
 * timer1 overflow happened
 */
#define INT8_TIMER1_OVF                _vector(9)

/*
 * timer0 compare match happened
 */
#define INT9_TIMER0_COMP               _vector(10)

/*
 * timer0 overflow happened
 */
#define INT10_TIMER0_OVF               _vector(11)

/*
 * spi transmition completed !
 */
#define INT11_SPI_STC                  _vector(12)

/*
 * usart Receiving completed !
 */
#define INT12_USART_RXC                _vector(13)


/*
 * usart data register empty.
 */
#define INT13_USART_UDRE              _vector(14)

/*
 * USART Transmission is completed
 */

#define INT14_USART_TXC              _vector(15)

/*
 * ADC conversion Completed
 */

#define INT15_ADC_CC                 _vector(16)

/*
 *
 * EEPROM is ready
 */

#define INT16_EE_RDY                _vector(17)

/*
 * analog comparator
 */
#define INT17_ANA_COMP             _vector(18)

/*
 * TWI interupt two wire serial interface
 */

#define INT18_TWI                  _vector(19)

/*
 * store program memory is ready !
 */

#define INT19_SPM_RDY              _vector(20)


#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)

#define INT_HANDLER(vector,...)	\
void vector(void) __attribute__((signal, used, external)) __VA_ARGS__;	\
void vector(void)




#define INT0_Handler()				INT_HANDLER(__vector_1)
#define INT1_Handler()				INT_HANDLER(__vector_2)
#define INT2_Handler()				INT_HANDLER(__vector_3)
#define TIMER2_COMP_Handler()		INT_HANDLER(__vector_4)
#define TIMER2_OVF_Handler()		INT_HANDLER(__vector_5)
#define TIMER1_CAPT_Handler()		INT_HANDLER(__vector_6)
#define TIMER1_COMPA_Handler()		INT_HANDLER(__vector_7)
#define TIMER1_COMPB_Handler()		INT_HANDLER(__vector_8)
#define TIMER1_OVF_Handler()		INT_HANDLER(__vector_9)
#define TIMER0_COMP_Handler()		INT_HANDLER(__vector_10)
#define TIMER0_OVF_Handler()		INT_HANDLER(__vector_11)
#define	SPI_STC_Handler()			INT_HANDLER(__vector_12)
#define USART_RXC_Handler()			INT_HANDLER(__vector_13)
#define USART_UDRE_Handler()		INT_HANDLER(__vector_14)
#define USART_TXC_Handler()			INT_HANDLER(__vector_15)
#define ADC_Handler()				INT_HANDLER(__vector_16)
#define EE_RDY_Handler()			INT_HANDLER(__vector_17)
#define ANA_COMP_Handler()			INT_HANDLER(__vector_18)
#define TWI_Handler()				INT_HANDLER(__vector_19)
#define SPM_RDY_Handler()			INT_HANDLER(__vector_20)


#define SREG          *((reg_type)(0x5F))
#define SREG_I        7
#define SREG_T        6
#define SREG_H        5
#define SREG_S        4
#define SREG_V        3
#define SREG_N        2
#define SREG_Z        1
#define SREG_C        0



/*
 *
 * defining two modes for either enabling or disabling the global interrupt
 */


#define GLOBAL_INTERRUPT_ENABLE     1
#define GLOBAL_INTERRUPT_DISABLE    0


void globalInterruptManipulate(uint8 globalInterruptState);









#endif /* INTERRUPT_H_ */
