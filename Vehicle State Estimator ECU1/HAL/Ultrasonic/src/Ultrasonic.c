/*
 * Ultrasonic.c
 *
 *  Created on: Oct 28, 2019
 *      Author: AVE-LAP-070
 */


#include"../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "../../Libraries/LIBRARIES_INCLUDES/SW_Delay.h"
#include "Dio.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Ext_Interrupt.h"
#include "Icu.h"
#include "UltrasonicCfg.h"
#include "Ultrasonic.h"

void initializeUltraSonic(void)
{

	AVE_gpioPinDirection(PORTA,BIT4,OUTPUT);
	AVE_gpioPinWrite(PORTA,BIT4,HIGH);
	AVE_gpioPinDirection(PORTA,BIT5,OUTPUT);
	AVE_gpioPinWrite(PORTA,BIT5,LOW);
	AVE_gpioPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,OUTPUT);
	SwICU_Init(ICU_TIMER0);

}


void triggerUltrasonic(void)
{

	AVE_gpioPinWrite(PORTA,BIT6,HIGH);
	_delay_us(15);
	AVE_gpioPinWrite(PORTA,BIT6,LOW);

}


uint32 calculateDistance(void)
{

	uint32 onTicks;
	SwICU_Read(&onTicks);

	long long int ontTime = onTicks*128;//in micro seconds

	uint32 velocity = 34000; //in cm

	uint32 distance = (((long long)ontTime*velocity/1000000UL))/2;

	triggerUltrasonic();
	return distance;





}
