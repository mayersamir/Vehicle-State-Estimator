/*
 * MDIO_Interface.h
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_



//definintion of ports

#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3





/************************************************************************/
/*				 Enum for defining bit numbers                          */
/************************************************************************/
typedef enum EN_bits
{
	BIT0 = 0x01,	// defines BIT0 in a register
	BIT1 = 0x02,	// defines BIT1 in a register
	BIT2 = 0x04,	// defines BIT2 in a register
	BIT3 = 0x08,	// defines BIT3 in a register
	BIT4 = 0x10,	// defines BIT4 in a register
	BIT5 = 0x20,	// defines BIT5 in a register
	BIT6 = 0x40,	// defines BIT6 in a register
	BIT7 = 0x80,	// defines BIT7 in a register
}EN_bits;





/************************************************************************/
/*				 		defining boolean values                         */
/************************************************************************/
#define FALSE 	0	// defines boolean false
#define TRUE 	1	// defines boolean true





/************************************************************************/
/*						 LOW/HIGH defines                               */
/************************************************************************/
#define LOW  0	// defines LOW value for a bit
#define HIGH 1	// defines HIGH value for a bit


//3 directions available for atmega32
#define     INPUT        0
#define     INPUT_PULLUP 1
#define     OUTPUT       2

void AVE_gpioIntialization(void);


void AVE_gpioPortDirection(uint8 port, uint8 direction);



void AVE_gpioPortWrite(uint8 port, uint8 value);



void AVE_gpioPortToggle(uint8 port);


void AVE_gpioPortRead(uint8 port,uint8*returnedValue);


void AVE_gpioPinRead(uint8 port, uint8 pin,uint8*value);

void AVE_gpioUpperNibbleDirection(uint8 port, uint8 direction);

void AVE_gpioUpperNibbleWrite(uint8 port, uint8 value);

void AVE_gpioLowerNibbleWrite(uint8 port, uint8 value);

void AVE_gpioLowerNibbleDirection(uint8 port, uint8 value);

void AVE_gpioUpperNibbleToggle(uint8 port);

void AVE_gpioLowerNibbleToggle(uint8 port);

void AVE_GpioLowerNibbleRead(uint8 port,uint8*returnedValue);

void AVE_GpioHighNibbleRead(uint8 port,uint8*returnedValue);

void AVE_gpioPinDirection(uint8 port, uint8 pins, uint8 direction);

void AVE_gpioPinToggle(uint8 port, uint8 pins);


void AVE_gpioPinWrite(uint8 port, uint8 pins, uint8 value);
#endif /* MDIO_INTERFACE_H_ */
