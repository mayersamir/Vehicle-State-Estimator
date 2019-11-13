/*
 * SpiManager.c
 *
 *  Created on: Nov 12, 2019
 *      Author: AVE-LAP-070
 */


#include "LTYPES.h"
#include "LUTILS.h"
#include "SpiCfg.h"
#include "Spi.h"
#include "Dio_Private.h"
#include "INTERRUPT.h"
#include "Dio.h"
#include "Led.h"
#include "SW_Delay.h"
#include "SpiManager.h"

uint8 arrOfSlavesPorts[NUMBER_OF_SLAVES] = {PORTB};
uint8 arrOfSlavesPins[NUMBER_OF_SLAVES]  = {BIT4};


void SpiManipulateMode(uint8 spiMode)
{


	switch(spiMode)
	{
	case SPI_MASTER:

		AVE_gpioPinDirection(CFG_PORT,MOSI,OUTPUT);
		AVE_gpioPinDirection(CFG_PORT,MISO,INPUT);
		AVE_gpioPinDirection(CFG_PORT,SPI_CLK,OUTPUT);
		for(uint8 i = 0;i<NUMBER_OF_SLAVES;i++)
		{
			AVE_gpioPinDirection(PORTB,BIT4,OUTPUT);
			AVE_gpioPinWrite(PORTB,BIT4,LOW);
		}



		break;
	case SPI_SLAVE:
		AVE_gpioPinDirection(CFG_PORT,MOSI,INPUT);
		AVE_gpioPinDirection(CFG_PORT,MISO,OUTPUT);
		AVE_gpioPinDirection(CFG_PORT,SPI_CLK,INPUT);
		AVE_gpioPinDirection(CFG_PORT,SLAVE_SELECT_PIN,INPUT);

		break;



	}

	Spi_Init(&spiCfg);


}

uint8 SpiSendData(uint8 data,uint8 flag)
{

	uint8 receivedData = 1;

	switch(flag)
	{
	case SEND:
		SpiTransferPolling(data);
		break;
	case RECEIVE:
		receivedData=SpiGetPolling();
		break;

	}

	return receivedData;

}
