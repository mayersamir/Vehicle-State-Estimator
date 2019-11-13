/*
 * communication.c
 *
 * Created: 11/13/2019 2:02:49 PM
 *  Author: AVE-LAP-44
 */ 



#include "SPI.h"
#include "UART.h"
#include "Timers.h"
#include "pushButton.h"
#include "SwDelay.h"

volatile uint8  Distance;
volatile uint32 Time_Delta;
volatile uint32 Time_Current;
volatile uint32 Time_Prev;
volatile uint32 Time_Init;
volatile uint8 Button_Flag;

#define DELAY_TIME 500
#define TIME_FACTOR 0

void Measurement_Init()
{
	Distance = FALSE;
	Time_Delta = FALSE;
	Time_Init = FALSE;
	Count_Flag = FALSE;
	Button_Flag = FALSE;
	Speed = FALSE;
	Time_Prev = FALSE;
	Time_Current = FALSE;
	SPI_Init(&SPI_Cfg_s);
	UART_Init(&UART_Cfg_s);
	Timers_Init(&timer1_cfg_s);
	pushButton_Init(pushButton0);
	pushButton_Init(pushButton1);
}

void Measurement_Calc()
{
	static uint8 Button_Flag2 = FALSE;
	if( pushButton_Get_Status(pushButton0))
	{
		Button_Flag2 = TRUE;
	}
	
	if( pushButton_Get_Status(pushButton1))
	{
		Button_Flag2 = FALSE;
	}
	
	if( Count_Flag  && Button_Flag2)
	{
		Time_Delta = Time_Current - Time_Prev;
		Distance  += (Time_Delta * Speed);
		Time_Prev = Time_Current;
	}
}

void Measurement_Send()
{
	UART_SendToTTL(Distance);
	SwDelay_ms(DELAY_TIME);
}
