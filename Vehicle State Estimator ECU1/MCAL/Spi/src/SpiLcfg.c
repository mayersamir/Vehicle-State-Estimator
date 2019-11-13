/*
 * SpiLcfg.c
 *
 *  Created on: Nov 12, 2019
 *      Author: AVE-LAP-070
 */

#include "LTYPES.h"
#include "LUTILS.h"
#include "SpiCfg.h"
#include "Spi.h"



spiConfiguration spiCfg = {CLK_FALLING_IDLE,CLK_SAMPLE_LEADING_SETUP_TRAILING,
		SPI_MASTER,LSB_TRANSMISSION_FIRST,CLK_FREQ_8,POSTCOMPILE};

