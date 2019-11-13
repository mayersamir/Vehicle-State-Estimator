/*
 * MDIO_SRC.c
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#include "../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"

#include "../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "Dio_Private.h"






/*
 *
 * it intializes the passed port which is one of the following
 * and sets the entire port whether input or output or even
 * input pullup.
 */


void AVE_gpioIntialization(void)
{


#if PORTA_BIT0 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT0);
#elif PORTA_BIT0 == INPUT
	CLR_PINS_VALUE(GPIOA_DDR,BIT0);
#elif PORTA_BIT0 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOA_DDR,BIT0);
	SET_PINS_VALUE(GPIOA_PORT,BIT0);
#endif


#if PORTA_BIT1 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT1);
#elif PORTA_BIT1 == INPUT
	CLR_PINS_VALUE(GPIOA_DDR,BIT1);
#elif PORTA_BIT1 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOA_DDR,BIT1);
	SET_PINS_VALUE(GPIOA_PORT,BIT1);
#endif



#if PORTA_BIT2 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT2);
#elif PORTA_BIT2 == INPUT
	CLR_PINS_VALUE(GPIOA_DDR,BIT2);
#elif PORTA_BIT2 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOA_DDR,BIT2);
	SET_PINS_VALUE(GPIOA_PORT,BIT2);
#endif


#if PORTA_BIT3 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT3);
#elif PORTA_BIT3 == INPUT
	CLR_PINS_VALUE(GPIOA_DDR,BIT3);
#elif PORTA_BIT3 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOA_DDR,BIT3);
	SET_PINS_VALUE(GPIOA_PORT,BIT3);
#endif



#if PORTA_BIT4 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT4);
#elif PORTA_BIT4 == INPUT
	CLR_PINS_VALUE(GPIOA_DDR,BIT4);
#elif PORTA_BIT4 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOA_DDR,BIT4);
	SET_PINS_VALUE(GPIOA_PORT,BIT4);
#endif



#if PORTA_BIT5 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT5);
#elif PORTA_BIT5 == INPUT
	CLR_PINS_VALUE(GPIOA_DDR,BIT5);
#elif PORTA_BIT5 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOA_DDR,BIT5);
	SET_PINS_VALUE(GPIOA_PORT,BIT5);
#endif



#if PORTA_BIT6 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT6);
#elif PORTA_BIT6 == INPUT
	CLR_PINS_VALUE(GPIOA_DDR,BIT6);
#elif PORTA_BIT6 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOA_DDR,BIT6);
	SET_PINS_VALUE(GPIOA_PORT,BIT6);
#endif


#if PORTA_BIT7 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT7);
#elif PORTA_BIT7 == INPUT
	CLR_PINS_VALUE(GPIOA_DDR,BIT7);
#elif PORTA_BIT7 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOA_DDR,BIT7);
	SET_PINS_VALUE(GPIOA_PORT,BIT7);
#endif




#if PORTB_BIT0 == OUTPUT
	SET_PINS_VALUE(GPIOB_DDR,BIT0);
#elif PORTB_BIT0 == INPUT
	CLR_PINS_VALUE(GPIOB_DDR,BIT0);
#elif PORTB_BIT0 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOB_DDR,BIT0);
	SET_PINS_VALUE(GPIOB_PORT,BIT0);
#endif


#if PORTB_BIT1 == OUTPUT
	SET_PINS_VALUE(GPIOA_DDR,BIT1);
#elif PORTB_BIT1 == INPUT
	CLR_PINS_VALUE(GPIOB_DDR,BIT1);
#elif PORTB_BIT1 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOB_DDR,BIT1);
	SET_PINS_VALUE(GPIOB_PORT,BIT1);
#endif



#if PORTB_BIT2 == OUTPUT
	SET_PINS_VALUE(GPIOB_DDR,BIT2);
#elif PORTB_BIT2 == INPUT
	CLR_PINS_VALUE(GPIOB_DDR,BIT2);
#elif PORTB_BIT2 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOB_DDR,BIT2);
	SET_PINS_VALUE(GPIOB_PORT,BIT2);
#endif


#if PORTB_BIT3 == OUTPUT
	SET_PINS_VALUE(GPIOB_DDR,BIT3);
#elif PORTB_BIT3 == INPUT
	CLR_PINS_VALUE(GPIOB_DDR,BIT3);
#elif PORTB_BIT3 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOB_DDR,BIT3);
	SET_PINS_VALUE(GPIOB_PORT,BIT3);
#endif



#if PORTB_BIT4 == OUTPUT
	SET_PINS_VALUE(GPIOB_DDR,BIT4);
#elif PORTB_BIT4 == INPUT
	CLR_PINS_VALUE(GPIOB_DDR,BIT4);
#elif PORTB_BIT4 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOB_DDR,BIT4);
	SET_PINS_VALUE(GPIOB_PORT,BIT4);
#endif



#if PORTB_BIT5 == OUTPUT
	SET_PINS_VALUE(GPIOB_DDR,BIT5);
#elif PORTB_BIT5 == INPUT
	CLR_PINS_VALUE(GPIOB_DDR,BIT5);
#elif PORTB_BIT5 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOB_DDR,BIT5);
	SET_PINS_VALUE(GPIOB_PORT,BIT5);
#endif



#if PORTB_BIT6 == OUTPUT
	SET_PINS_VALUE(GPIOB_DDR,BIT6);
#elif PORTB_BIT6 == INPUT
	CLR_PINS_VALUE(GPIOB_DDR,BIT6);
#elif PORTB_BIT6 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOB_DDR,BIT6);
	SET_PINS_VALUE(GPIOB_PORT,BIT6);
#endif


#if PORTB_BIT7 == OUTPUT
	SET_PINS_VALUE(GPIOB_DDR,BIT7);
#elif PORTB_BIT7 == INPUT
	CLR_PINS_VALUE(GPIOB_DDR,BIT7);
#elif PORTB_BIT7 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOB_DDR,BIT7);
	SET_PINS_VALUE(GPIOB_PORT,BIT7);
#endif




#if PORTC_BIT0 == OUTPUT
	SET_PINS_VALUE(GPIOC_DDR,BIT0);
#elif PORTC_BIT0 == INPUT
	CLR_PINS_VALUE(GPIOC_DDR,BIT0);
#elif PORTC_BIT0 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOC_DDR,BIT0);
	SET_PINS_VALUE(GPIOC_PORT,BIT0);
#endif


#if PORTC_BIT1 == OUTPUT
	SET_PINS_VALUE(GPIOC_DDR,BIT1);
#elif PORTC_BIT1 == INPUT
	CLR_PINS_VALUE(GPIOC_DDR,BIT1);
#elif PORTC_BIT1 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOC_DDR,BIT1);
	SET_PINS_VALUE(GPIOC_PORT,BIT1);
#endif



#if PORTC_BIT2 == OUTPUT
	SET_PINS_VALUE(GPIOC_DDR,BIT2);
#elif PORTC_BIT2 == INPUT
	CLR_PINS_VALUE(GPIOC_DDR,BIT2);
#elif PORTC_BIT2 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOC_DDR,BIT2);
	SET_PINS_VALUE(GPIOC_PORT,BIT2);
#endif


#if PORTC_BIT3 == OUTPUT
	SET_PINS_VALUE(GPIOC_DDR,BIT3);
#elif PORTC_BIT3 == INPUT
	CLR_PINS_VALUE(GPIOC_DDR,BIT3);
#elif PORTC_BIT3 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOC_DDR,BIT3);
	SET_PINS_VALUE(GPIOC_PORT,BIT3);
#endif



#if PORTC_BIT4 == OUTPUT
	SET_PINS_VALUE(GPIOC_DDR,BIT4);
#elif PORTC_BIT4 == INPUT
	CLR_PINS_VALUE(GPIOC_DDR,BIT4);
#elif PORTC_BIT4 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOC_DDR,BIT4);
	SET_PINS_VALUE(GPIOC_PORT,BIT4);
#endif



#if PORTC_BIT5 == OUTPUT
	SET_PINS_VALUE(GPIOC_DDR,BIT5);
#elif PORTC_BIT5 == INPUT
	CLR_PINS_VALUE(GPIOC_DDR,BIT5);
#elif PORTC_BIT5 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOC_DDR,BIT5);
	SET_PINS_VALUE(GPIOC_PORT,BIT5);
#endif



#if PORTC_BIT6 == OUTPUT
	SET_PINS_VALUE(GPIOC_DDR,BIT6);
#elif PORTC_BIT6 == INPUT
	CLR_PINS_VALUE(GPIOC_DDR,BIT6);
#elif PORTC_BIT6 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOC_DDR,BIT6);
	SET_PINS_VALUE(GPIOC_PORT,BIT6);
#endif


#if PORTC_BIT7 == OUTPUT
	SET_PINS_VALUE(GPIOC_DDR,BIT7);
#elif PORTC_BIT7 == INPUT
	CLR_PINS_VALUE(GPIOC_DDR,BIT7);
#elif PORTC_BIT7 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOC_DDR,BIT7);
	SET_PINS_VALUE(GPIOC_PORT,BIT7);
#endif





#if PORTD_BIT0 == OUTPUT
	SET_PINS_VALUE(GPIOD_DDR,BIT0);
#elif PORTD_BIT0 == INPUT
	CLR_PINS_VALUE(GPIOD_DDR,BIT0);
#elif PORTD_BIT0 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOD_DDR,BIT0);
	SET_PINS_VALUE(GPIOD_PORT,BIT0);
#endif


#if PORTD_BIT1 == OUTPUT
	SET_PINS_VALUE(GPIOD_DDR,BIT1);
#elif PORTD_BIT1 == INPUT
	CLR_PINS_VALUE(GPIOD_DDR,BIT1);
#elif PORTD_BIT1 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOD_DDR,BIT1);
	SET_PINS_VALUE(GPIOD_PORT,BIT1);
#endif



#if PORTD_BIT2 == OUTPUT
	SET_PINS_VALUE(GPIOD_DDR,BIT2);
#elif PORTD_BIT2 == INPUT
	CLR_PINS_VALUE(GPIOD_DDR,BIT2);
#elif PORTD_BIT2 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOD_DDR,BIT2);
	SET_PINS_VALUE(GPIOD_PORT,BIT2);
#endif


#if PORTD_BIT3 == OUTPUT
	SET_PINS_VALUE(GPIOD_DDR,BIT3);
#elif PORTD_BIT3 == INPUT
	CLR_PINS_VALUE(GPIOD_DDR,BIT3);
#elif PORTD_BIT3 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOD_DDR,BIT3);
	SET_PINS_VALUE(GPIOD_PORT,BIT3);
#endif



#if PORTD_BIT4 == OUTPUT
	SET_PINS_VALUE(GPIOD_DDR,BIT4);
#elif PORTD_BIT4 == INPUT
	CLR_PINS_VALUE(GPIOD_DDR,BIT4);
#elif PORTD_BIT4 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOD_DDR,BIT4);
	SET_PINS_VALUE(GPIOD_PORT,BIT4);
#endif



#if PORTD_BIT5 == OUTPUT
	SET_PINS_VALUE(GPIOD_DDR,BIT5);
#elif PORTD_BIT5 == INPUT
	CLR_PINS_VALUE(GPIOD_DDR,BIT5);
#elif PORTD_BIT5 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOD_DDR,BIT5);
	SET_PINS_VALUE(GPIOD_PORT,BIT5);
#endif



#if PORTD_BIT6 == OUTPUT
	SET_PINS_VALUE(GPIOD_DDR,BIT6);
#elif PORTD_BIT6 == INPUT
	CLR_PINS_VALUE(GPIOD_DDR,BIT6);
#elif PORTD_BIT6 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOD_DDR,BIT6);
	SET_PINS_VALUE(GPIOD_PORT,BIT6);
#endif


#if PORTD_BIT7 == OUTPUT
	SET_PINS_VALUE(GPIOD_DDR,BIT7);
#elif PORTD_BIT7 == INPUT
	CLR_PINS_VALUE(GPIOD_DDR,BIT7);
#elif PORTD_BIT7 == INPUT_PULLUP
	CLR_PINS_VALUE(GPIOD_DDR,BIT7);
	SET_PINS_VALUE(GPIOD_PORT,BIT7);
#endif



}

void AVE_gpioPortDirection(uint8 port, uint8 direction)
{


	switch(port)
	{
	case PORTA:
		switch(direction)
		{
		case INPUT:
			GPIOA_DDR = GPIO_ALL_INBUT;
			break;
		case OUTPUT:
			GPIOA_DDR = GPIO_ALL_OUTPUT;
			break;
		case INPUT_PULLUP:
			GPIOA_DDR = GPIO_ALL_INBUT;
			GPIOA_PORT = GPIO_ALL_OUTPUT;
			break;
		}
	break;

	case PORTB:
		switch(direction)
				{
				case INPUT:
					GPIOB_DDR = GPIO_ALL_INBUT;
					break;
				case OUTPUT:
					GPIOB_DDR = GPIO_ALL_OUTPUT;
					break;
				case INPUT_PULLUP:
					GPIOB_DDR = GPIO_ALL_INBUT;
					GPIOB_PORT = GPIO_ALL_OUTPUT;
					break;
				}
	break;

	case PORTC:
		switch(direction)
				{
				case INPUT:
					GPIOC_DDR = GPIO_ALL_INBUT;
					break;
				case OUTPUT:
					GPIOC_DDR = GPIO_ALL_OUTPUT;
					break;
				case INPUT_PULLUP:
					GPIOC_DDR = GPIO_ALL_INBUT;
					GPIOC_PORT = GPIO_ALL_OUTPUT;
					break;
				}
	break;

	case PORTD:
		switch(direction)
				{
				case INPUT:
					GPIOD_DDR = GPIO_ALL_INBUT;
					break;
				case OUTPUT:
					GPIOD_DDR = GPIO_ALL_OUTPUT;
					break;
				case INPUT_PULLUP:
					GPIOD_DDR = GPIO_ALL_INBUT;
					GPIOD_PORT = GPIO_ALL_OUTPUT;
					break;
				}
	break;


    }


}



/*
 *
 * it writes a specific value on a previously intialzed port as an output!
 *
 *
 */
void AVE_gpioPortWrite(uint8 port, uint8 value)
{

	switch(port)
	{

	case PORTA:
		switch(value)
		{
		case HIGH:
			SET_REG(GPIOA_PORT);
			break;
		case LOW:
			CLEAR_REG(GPIOA_PORT);
			break;


		}

		break;
	case PORTB:
		switch(value)
		{

		case HIGH:
			SET_REG(GPIOB_PORT);
			break;
		case LOW:
			CLEAR_REG(GPIOB_PORT);
			break;


		}

		break;
	case PORTC:
		switch(value)
		{
		case HIGH:
			SET_REG(GPIOC_PORT);
			break;
		case LOW:
			CLEAR_REG(GPIOC_PORT);
			break;

		}
		break;
	case PORTD:
		switch(value)
		{
		case HIGH:
			SET_REG(GPIOD_PORT);
			break;
		case LOW:
			CLEAR_REG(GPIOD_PORT);
			break;

		}
		break;

	}
}


/*
 *
 * it toggles the value of the output port
 * if it is high value it
 * toggles to low
 * or low to high !
 * takes as an argument one of the 4 ports A,B,C,D
 */

void AVE_gpioPortToggle(uint8 port)
{

	switch(port)
	{


	case PORTA:
		GPIOA_PORT ^= GPIO_ALL_TOGGLE;
		break;
	case PORTB:
		GPIOB_PORT ^= GPIO_ALL_TOGGLE;
		break;
	case PORTC:
		GPIOC_PORT ^= GPIO_ALL_TOGGLE;
		break;
	case PORTD:
		GPIOD_PORT ^= GPIO_ALL_TOGGLE;
		break;

	}

}

/*
 *
 * it returns the value of the specified port
 * the port must be intialized as an input port
 * before you can even use this function to get the value
 * of the port
 *
 */
void AVE_gpioPortRead(uint8 port,uint8*returnedValue)
{


	switch(port)
	{

	case PORTA:
		*returnedValue = GPIOA_PIN;
		break;
	case PORTB:
		*returnedValue = GPIOB_PIN;
		break;
	case PORTC:
		*returnedValue = GPIOC_PIN;
		break;
	case PORTD:
		*returnedValue = GPIOD_PIN;
		break;
	}


	return;


}


/*
 *
 * it defines the direction of a pin inside a port to be one of the three
 * available mode whether input or output or input pull up .
 *
 */

void AVE_gpioPinDirection(uint8 port, uint8 pins, uint8 direction)
{
	switch(port)
	{

		case PORTA:
			switch(direction)
			{
				case INPUT:
					CLR_PINS_VALUE(GPIOA_DDR,pins);
					break;
				case OUTPUT:
					SET_PINS_VALUE(GPIOA_DDR,pins);
					break;
				case INPUT_PULLUP:
					CLR_PINS_VALUE(GPIOA_DDR,pins);
					SET_PINS_VALUE(GPIOA_PORT,pins);
					break;
			}
		break;
	case PORTB:
			switch(direction)
			{
			case INPUT:
				CLR_PINS_VALUE(GPIOB_DDR,pins);
				break;
			case OUTPUT:
				SET_PINS_VALUE(GPIOB_DDR,pins);
				break;
			case INPUT_PULLUP:
				CLR_PINS_VALUE(GPIOB_DDR,pins);
				SET_PINS_VALUE(GPIOB_PORT,pins);
				break;

			}
			break;

	case PORTC:
			switch(direction)
			{
			case INPUT:
				CLR_PINS_VALUE(GPIOC_DDR,pins);
				break;
			case OUTPUT:
				SET_PINS_VALUE(GPIOC_DDR,pins);
				break;
			case INPUT_PULLUP:
				CLR_PINS_VALUE(GPIOC_DDR,pins);
				SET_PINS_VALUE(GPIOC_PORT,pins);
				break;

			}
			break;

	case PORTD:
			switch(direction)
			{
			case INPUT:
				CLR_PINS_VALUE(GPIOD_DDR,pins);
				break;
			case OUTPUT:
				SET_PINS_VALUE(GPIOD_DDR,pins);
				break;
			case INPUT_PULLUP:
				CLR_PINS_VALUE(GPIOD_DDR,pins);
				SET_PINS_VALUE(GPIOD_PORT,pins);
				break;

			}
			break;



	}
}


/*
 *
 * this function is used internally inside our file to mapp the bit value to the value
 * of a pin inside a port !.
 */

static void AVE_BittsMappedToPins(uint8 Bit,uint8* Pin)
{
	uint8 counter = 0;
	while(Bit/2)
	{
		counter++;
		Bit/=2;

	}

	*Pin = counter;



}


/*
 *
 * this value is used to write the value of a pin inside a port
 * you specify the port
 * then you specify the pin to be set for that value
 * the value is one of the two following HIGH or LOW !.
 *
 */

void AVE_gpioPinWrite(uint8 port, uint8 pins, uint8 value)
{
	uint8 pin;
	AVE_BittsMappedToPins(pins,&pin);

	switch(port)
	{
	case PORTA:
		switch(value)
		{
		case HIGH:
			SET_BIT(GPIOA_PORT,pin);
			break;
		case LOW:
			CLEAR_BIT(GPIOA_PORT,pin);
			break;


		}


		break;
	case PORTB:
		switch(value)
		{

		case HIGH:
			SET_BIT(GPIOB_PORT,pin);
			break;
		case LOW:
			CLEAR_BIT(GPIOB_PORT,pin);
			break;


		}


		break;
	case PORTC:
		switch(value)
		{
		case HIGH:
			SET_BIT(GPIOC_PORT,pin);
			break;
		case LOW:
			CLEAR_BIT(GPIOC_PORT,pin);
			break;



		}


		break;
	case PORTD:
		switch(value)
		{
		case HIGH:
			SET_BIT(GPIOD_PORT,pin);
			break;
		case LOW:
			CLEAR_BIT(GPIOD_PORT,pin);
			break;


		}


		break;
	}
}


/*
 *
 *
 * this function is used to toggle the value of a pin of a port
 * the pin must previously set as output in order for that function to be
 * work correctly !.
 */

void AVE_gpioPinToggle(uint8 port, uint8 pins)
{

	switch(port)
	{

	case PORTA:
		TOGGLE_PINS(GPIOA_PORT,pins);
		break;
	case PORTB:
		TOGGLE_PINS(GPIOB_PORT,pins);
		break;
	case PORTC:
		TOGGLE_PINS(GPIOC_PORT,pins);
		break;
	case PORTD:
		TOGGLE_PINS(GPIOD_PORT,pins);
		break;

	}
}

/*
 *
 * this function is used to read the value of a pin of a port
 * you pass a pointer to variable that you want
 * to be filled with the value of a specified pin inside a port.
 *
 */

void AVE_gpioPinRead(uint8 port, uint8 pin,uint8*value)
{

	uint8 PIN;
	AVE_BittsMappedToPins(pin,&PIN);

	switch(port)
	{

	case PORTA:
		*value = GET_BIT(GPIOA_PIN,PIN);
		break;
	case PORTB:
		*value = GET_BIT(GPIOB_PIN,PIN);
		break;
	case PORTC:
		*value = GET_BIT(GPIOC_PIN,PIN);
		break;
	case PORTD:
		*value = GET_BIT(GPIOD_PIN,PIN);
		break;

	}
	return;




}

void AVE_gpioUpperNibbleDirection(uint8 port, uint8 direction)
{

	switch(port)
	{

	case PORTA:
		switch(direction)
		{
		case INPUT:
			CLEAR_4_HIGH_NIPPLE(GPIOA_DDR);
			break;
		case OUTPUT:
			SET_4_HIGH_NIPPLE(GPIOA_DDR);
			break;
		case INPUT_PULLUP:
			CLEAR_4_HIGH_NIPPLE(GPIOA_DDR);
			SET_4_HIGH_NIPPLE(GPIOA_PORT);
			break;

		}
		break;
	case PORTB:
			switch(direction)
			{
			case INPUT:
				CLEAR_4_HIGH_NIPPLE(GPIOB_DDR);
				break;
			case OUTPUT:
				SET_4_HIGH_NIPPLE(GPIOB_DDR);
				break;
			case INPUT_PULLUP:
				CLEAR_4_HIGH_NIPPLE(GPIOB_DDR);
				SET_4_HIGH_NIPPLE(GPIOB_PORT);
				break;

			}
			break;

	case PORTC:
			switch(direction)
			{
			case INPUT:
				CLEAR_4_HIGH_NIPPLE(GPIOC_DDR);
				break;
			case OUTPUT:
				SET_4_HIGH_NIPPLE(GPIOC_DDR);
				break;
			case INPUT_PULLUP:
				CLEAR_4_HIGH_NIPPLE(GPIOC_DDR);
				SET_4_HIGH_NIPPLE(GPIOC_PORT);
				break;

			}
			break;

	case PORTD:
			switch(direction)
			{
			case INPUT:
				CLEAR_4_HIGH_NIPPLE(GPIOD_DDR);
				break;
			case OUTPUT:
				SET_4_HIGH_NIPPLE(GPIOD_DDR);
				break;
			case INPUT_PULLUP:
				CLEAR_4_HIGH_NIPPLE(GPIOD_DDR);
				SET_4_HIGH_NIPPLE(GPIOD_PORT);
				break;

			}
			break;



	}
}

/*
 *
 * this function is used to set the direction of a lower nibble of any port
 * the direction must be one of the following INPUT or OUTPUT or INPUT_PULLUP
 *
 */

void AVE_gpioLowerNibbleDirection(uint8 port, uint8 direction)
{


	switch(port)
	{

	case PORTA:
		switch(direction)
		{
		case INPUT:
			CLEAR_4_LOW_NIPPLE(GPIOA_DDR);
			break;
		case OUTPUT:
			SET_4_LOW_NIPPLE(GPIOA_DDR);
			break;
		case INPUT_PULLUP:
			CLEAR_4_LOW_NIPPLE(GPIOA_DDR);
			SET_4_LOW_NIPPLE(GPIOA_PORT);
			break;

		}
		break;
	case PORTB:
			switch(direction)
			{
			case INPUT:
				CLEAR_4_LOW_NIPPLE(GPIOB_DDR);
				break;
			case OUTPUT:
				SET_4_LOW_NIPPLE(GPIOB_DDR);
				break;
			case INPUT_PULLUP:
				CLEAR_4_LOW_NIPPLE(GPIOB_DDR);
				SET_4_LOW_NIPPLE(GPIOB_PORT);
				break;

			}
			break;

	case PORTC:
			switch(direction)
			{
			case INPUT:
				CLEAR_4_LOW_NIPPLE(GPIOC_DDR);
				break;
			case OUTPUT:
				SET_4_LOW_NIPPLE(GPIOC_DDR);
				break;
			case INPUT_PULLUP:
				CLEAR_4_LOW_NIPPLE(GPIOC_DDR);
				SET_4_LOW_NIPPLE(GPIOC_PORT);
				break;

			}
			break;

	case PORTD:
			switch(direction)
			{
			case INPUT:
				CLEAR_4_LOW_NIPPLE(GPIOD_DDR);
				break;
			case OUTPUT:
				SET_4_LOW_NIPPLE(GPIOD_DDR);
				break;
			case INPUT_PULLUP:
				CLEAR_4_LOW_NIPPLE(GPIOD_DDR);
				SET_4_LOW_NIPPLE(GPIOD_PORT);
				break;

			}
			break;



	}


}

/*
 *
 * this function is used to write the value of an upper nibble of a register
 * value must be one of two HIGH or LOW .
 */

void AVE_gpioUpperNibbleWrite(uint8 port, uint8 value)
{

	switch(port)
	{

	case PORTA:
		switch(value)
		{
		case HIGH:
			SET_4_HIGH_NIPPLE(GPIOA_PORT);
			break;
		case LOW:
			CLEAR_4_HIGH_NIPPLE(GPIOA_PORT);
			break;

		}
		break;
		case PORTB:
			switch(value)
			{
			case HIGH:
				SET_4_HIGH_NIPPLE(GPIOB_PORT);
				break;
			case LOW:
				CLEAR_4_HIGH_NIPPLE(GPIOB_PORT);
				break;

			}
			break;
		case PORTC:
			switch(value)
			{
			case HIGH:
				SET_4_HIGH_NIPPLE(GPIOC_PORT);
				break;
			case LOW:
				CLEAR_4_HIGH_NIPPLE(GPIOC_PORT);
				break;
			}
			break;
		case PORTD:
			switch(value)
			{
			case HIGH:
				SET_4_HIGH_NIPPLE(GPIOD_PORT);
				break;
			case LOW:
				CLEAR_4_HIGH_NIPPLE(GPIOD_PORT);
				break;
			}
			break;

	}
}


/*
 *
 * this function is used to write the value of the lower nibble of a register
 * the value can be one of two High or low .
 */

void AVE_gpioLowerNibbleWrite(uint8 port, uint8 value)
{

	switch(port)
	{

	case PORTA:
		switch(value)
		{
		case HIGH:
			SET_4_LOW_NIPPLE(GPIOA_PORT);
			break;
		case LOW:
			CLEAR_4_LOW_NIPPLE(GPIOA_PORT);
			break;

		}
		break;
		case PORTB:
//			switch(value)
//			{
//			case HIGH:
//				SET_4_LOW_NIPPLE(GPIOB_PORT);
//				break;
//			case LOW:
//				CLEAR_4_LOW_NIPPLE(GPIOB_PORT);
//				break;
//
//			}
			GPIOB_PORT&=(0xF0);
			GPIOB_PORT|=value;
			break;
		case PORTC:
			switch(value)
			{
			case HIGH:
				SET_4_LOW_NIPPLE(GPIOC_PORT);
				break;
			case LOW:
				CLEAR_4_LOW_NIPPLE(GPIOC_PORT);
				break;
			}
			break;
		case PORTD:
			switch(value)
			{
			case HIGH:
				SET_4_LOW_NIPPLE(GPIOD_PORT);
				break;
			case LOW:
				CLEAR_4_LOW_NIPPLE(GPIOD_PORT);
				break;
			}
			break;

	}
}


/*
 *
 * this function is used to toggle the value of the upper nibble of the specified port
 * this nibble must be previously intialized as an output nibble.
 */
void AVE_gpioUpperNibbleToggle(uint8 port)
{
	switch(port)
	{
	case PORTA:
		TOGGLE_HIGH_NIBBLE(GPIOA_PORT);
		break;
	case PORTB:
		TOGGLE_HIGH_NIBBLE(GPIOB_PORT);
		break;
	case PORTC:
		TOGGLE_HIGH_NIBBLE(GPIOC_PORT);
		break;
	case PORTD:
		TOGGLE_HIGH_NIBBLE(GPIOD_PORT);
		break;


	}
}


/*
 *
 * this function is for toggling the value of the lower nibble of a register
 * the lower nibble direction must previously be set as output .
 */
void AVE_gpioLowerNibbleToggle(uint8 port)
{

	switch(port)
	{
	case PORTA:
		TOGGLE_LOWER_NIBBLE(GPIOA_PORT);
		break;
	case PORTB:
		TOGGLE_LOWER_NIBBLE(GPIOB_PORT);
		break;
	case PORTC:
		TOGGLE_LOWER_NIBBLE(GPIOC_PORT);
		break;
	case PORTD:
		TOGGLE_LOWER_NIBBLE(GPIOD_PORT);
		break;


	}

}


/*
 *
 * this function is for reading the upper nibble of a register which
 * is previously set as input
 * note you pass in a pointer to variable in order to populate it with
 * the upper nibble of a register .
 */
void AVE_gpioUpperNibbleRead(uint8 port,uint8*returnedValue)
{

	switch(port)
	{
	case PORTA:
		*returnedValue = Get_4_HIGH_NIBBLE(GPIOA_PORT);
		break;
	case PORTB:
		*returnedValue = Get_4_HIGH_NIBBLE(GPIOB_PORT);
		break;
	case PORTC:
		*returnedValue = Get_4_HIGH_NIBBLE(GPIOC_PORT);
		break;
	case PORTD:
		*returnedValue = Get_4_HIGH_NIBBLE(GPIOD_PORT);
		break;

	}


}
/*
 *
 * this function is for reading the lower nibble of a register which
 * previously intialized as input
 * and the returned value is passed as a parameter to the function .
 *
 */
void AVE_GpioLowerNibbleRead(uint8 port,uint8*returnedValue)
{
	switch(port)
	{
	case PORTA:
		*returnedValue = Get_4_LOW_NIBBLE(GPIOA_PORT);
		break;
	case PORTB:
		*returnedValue = Get_4_LOW_NIBBLE(GPIOB_PORT);
		break;
	case PORTC:
		*returnedValue = Get_4_LOW_NIBBLE(GPIOC_PORT);
		break;
	case PORTD:
		*returnedValue = Get_4_LOW_NIBBLE(GPIOD_PORT);
		break;
	}
	return;
}
