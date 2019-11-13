/*
 * SpiCfg.h
 *
 *  Created on: Nov 12, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_SPI_INC_SPICFG_H_
#define MCAL_SPI_INC_SPICFG_H_




typedef struct spiConfiguration
{

	uint8 spiPolarity;
	uint8 spiPhase;
	uint8 spiMode;
	uint8 bitOrder;
	uint8 clkSpeed;
	uint8 linkingType;
}spiConfiguration;


extern spiConfiguration spiCfg;

#endif /* MCAL_SPI_INC_SPICFG_H_ */
