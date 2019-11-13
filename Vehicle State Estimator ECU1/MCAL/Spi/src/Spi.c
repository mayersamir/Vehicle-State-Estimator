/*
 * Spi.c
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



static volatile uint8 data;

void (*spiHandler)(void);

void Spi_Enable(uint8 activationFlag)
{

	switch(activationFlag)
	{
	case SPI_ENABLE:
		SET_BIT(SPI_SPCR,SPCR_SPE);
		break;
	case SPI_DISABLE:
		CLEAR_BIT(SPI_SPCR,SPCR_SPE);
		break;
	default:
		SET_BIT(SPI_SPCR,SPCR_SPE);
		break;

	}

	return ;
}

void Spi_SetCallBack(void(*ptr)(void))
{
	spiHandler = ptr;
}

void Spi_Init(spiConfiguration*spiCfgPtr)
{

	/*
	 * for enabling the spi module .
	 */
//	AVE_gpioPinDirection(PORTB,BIT4,OUTPUT);
//	AVE_gpioPinWrite(PORTB,BIT4,LOW);

		uint8 spicrVar = 0;
	SET_BIT(spicrVar,SPCR_SPE);



	switch(spiCfgPtr->linkingType)
	{
	case PRECOMPILE:
		/*
		 * do nothing for now
		 * for future upgrade
		 */
		break;
	case POSTCOMPILE:
		switch(spiCfgPtr->spiMode)
		{
		case SPI_MASTER:
			SET_BIT(spicrVar,SPCR_MSTR);
			break;
		case SPI_SLAVE:
			CLEAR_BIT(spicrVar,SPCR_MSTR);
			break;
		default:
			break;

		}
		switch(spiCfgPtr->clkSpeed)
		{
		case CLK_FREQ_16:
			SET_BIT(spicrVar,SPCR_SPR0);
			CLEAR_BIT(spicrVar,SPCR_SPR1);
			CLEAR_BIT(SPI_SPSR,SPSR_SPI2X);
			break;
		case CLK_FREQ_4:
			CLEAR_BIT(spicrVar,SPCR_SPR0);
			CLEAR_BIT(spicrVar,SPCR_SPR1);
			CLEAR_BIT(SPI_SPSR,SPSR_SPI2X);
			break;
		case CLK_FREQ_64:
			CLEAR_BIT(spicrVar,SPCR_SPR0);
			SET_BIT(spicrVar,SPCR_SPR1);
			CLEAR_BIT(SPI_SPSR,SPSR_SPI2X);
			break;
		case CLK_FREQ_128:
			SET_BIT(spicrVar,SPCR_SPR0);
			SET_BIT(spicrVar,SPCR_SPR1);
			CLEAR_BIT(SPI_SPSR,SPSR_SPI2X);
			break;
		case CLK_FREQ_2:
			CLEAR_BIT(spicrVar,SPCR_SPR0);
			CLEAR_BIT(spicrVar,SPCR_SPR1);
			SET_BIT(SPI_SPSR,SPSR_SPI2X);
			break;
		case CLK_FREQ_8:
			SET_BIT(spicrVar,SPCR_SPR0);
			CLEAR_BIT(spicrVar,SPCR_SPR1);
			SET_BIT(SPI_SPSR,SPSR_SPI2X);
			break;
		case CLK_FREQ_32:
			CLEAR_BIT(spicrVar,SPCR_SPR0);
			SET_BIT(spicrVar,SPCR_SPR1);
			SET_BIT(SPI_SPSR,SPSR_SPI2X);
			break;

		default:
			break;

		}
		switch(spiCfgPtr->spiPhase)
		{
		case CLK_SAMPLE_LEADING_SETUP_TRAILING:
			CLEAR_BIT(spicrVar,SPCR_CPHA);
			break;
		case CLK_SAMPLE_TRAILING_SETUP_LEADING:
			SET_BIT(spicrVar,SPCR_CPHA);
			break;
		default:
			break;


		}
		switch(spiCfgPtr->spiPolarity)
		{
		case CLK_RISING_IDLE:
			CLEAR_BIT(spicrVar,SPCR_CPOL);
			break;
		case CLK_FALLING_IDLE:
			SET_BIT(spicrVar,SPCR_CPOL);
			break;
		default:
			break;

		}
		switch(spiCfgPtr->bitOrder)
		{
		case LSB_TRANSMISSION_FIRST:
			SET_BIT(spicrVar,SPCR_DORD);
			break;
		case MSB_TRANSMISSION_FIRST:
			CLEAR_BIT(spicrVar,SPCR_DORD);
			break;
		default:
			break;

		}

	}


	SPI_SPCR =spicrVar;// ((1<<SPCR_MSTR)|(1<<SPCR_SPE));

}


void SpiTransferPolling(uint8 data)
{

	SPI_SPDR = data;

	while((SPI_SPSR&(1<<7))!=(1<<7));

	//data = SPI_SPDR;

	return ;


}




uint8 SpiGetPolling(void)
{
	uint8 data;


	while(!(GET_BIT(SPI_SPSR,SPSR_SPIF)));

	data = SPI_SPDR;
	return data;


}

SPI_STC_Handler()
{
	SPI_SPDR = data;




}
