/*
 * MDIO_Private.h
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_


//3 registers for the first PORTA
#define         GPIOA_PORT           *((volatile uint8*const)(0x3B))
#define         GPIOA_DDR            *((volatile uint8*const)(0x3A))
#define         GPIOA_PIN            *((volatile uint8*const)(0x39))


//3 registers for the second PORTB

#define         GPIOB_PORT           *((volatile uint8*const)(0x38))
#define         GPIOB_DDR            *((volatile uint8*const)(0x37))
#define         GPIOB_PIN            *((volatile uint8*const)(0x36))

//3 registers for the third PORTC

#define         GPIOC_PORT           *((volatile uint8*const)(0x35))
#define         GPIOC_DDR            *((volatile uint8*const)(0x34))
#define         GPIOC_PIN            *((volatile uint8*const)(0x33))

//3 registers for the fourth PORTD

#define         GPIOD_PORT           *((volatile uint8*const)(0x32))
#define         GPIOD_DDR            *((volatile uint8*const)(0x31))
#define         GPIOD_PIN            *((volatile uint8*const)(0x30))




#define        GPIO_ALL_INBUT        (0x00)
#define        GPIO_ALL_OUTPUT       (0xFF)

#define        GPIO_ALL_TOGGLE       (0xFF)

#define        GPIO_LOWER_TOGGLE     (0xF0)
#define        GPIO_HIGH_TOGGLE      (0x0F)


#endif /* MDIO_PRIVATE_H_ */
