/*
 * EXTI_Private.h
 *
 *  Created on: Oct 26, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPTPRIVATE_H_
#define MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPTPRIVATE_H_

#define EXTI_MCUCR          *((reg_type)(0x55))
#define MCUCR_ISC00         0
#define MCUCR_ISC01         1
#define MCUCR_ISC10         2
#define MCUCR_ISC11         3



#define EXTI_MCUCSR         *((reg_type)(0x54))
#define MCUCSR_ISC2         6


#define EXTI_GICR           *((reg_type)(0x5B))
#define GICR_INT0           6
#define GICR_INT1           7
#define GICR_INT2           5


#define EXTI_GIFR           *((reg_type)(0x5A))
#define GIFR_INTF2          5
#define GIFR_INTF1          7
#define GIFR_INTF0          6





#endif /* MCAL_EXT_INTERRUPT_INC_EXT_INTERRUPTPRIVATE_H_ */
