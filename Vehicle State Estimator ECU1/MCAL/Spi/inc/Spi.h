/*
 * Spi.h
 *
 *  Created on: Nov 12, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_SPI_INC_SPI_H_
#define MCAL_SPI_INC_SPI_H_

#define SPCR_SPR0         0
#define SPCR_SPR1         1
#define SPCR_CPHA         2
#define SPCR_CPOL         3
#define SPCR_MSTR         4
#define SPCR_DORD         5
#define SPCR_SPE          6
#define SPCR_SPIE         7
#define SPI_SPCR          *((reg_type)(0x2D))










#define SPSR_SPI2X        0
#define SPSR_WCOL         6
#define SPSR_SPIF         7
#define SPI_SPSR          *((reg_type)(0x2E))





#define SPI_SPDR         *((reg_type)(0x2F))




#define SPI_ENABLE       1
#define SPI_DISABLE      0





#define PRECOMPILE       0
#define POSTCOMPILE      1

/*
 * configuration for the order of transmitting or receiving bits
 * for spi
 */
#define LSB_TRANSMISSION_FIRST    0
#define MSB_TRANSMISSION_FIRST    1

/*
 * configuration choices for spi mode
 */
#define SPI_MASTER                 0
#define SPI_SLAVE                  1

/*
 * configuration for the polarity of the clock used
 */
#define CLK_RISING_IDLE            0
#define CLK_FALLING_IDLE           1

/*
 * configuration for the clock phase
 */
#define CLK_SAMPLE_LEADING_SETUP_TRAILING   0
#define CLK_SAMPLE_TRAILING_SETUP_LEADING   1

/*
 * configuration of clock frequencies that spi can
 * work with
 */

#define CLK_FREQ_4                           0
#define CLK_FREQ_16                          1
#define CLK_FREQ_64                          2
#define CLK_FREQ_128                         3
#define CLK_FREQ_2                           4
#define CLK_FREQ_8                           5

#define CLK_FREQ_32                          6


void Spi_Enable(uint8 activationFlag);

void Spi_Init(spiConfiguration*spiCfgPtr);

void SpiTransferPolling(uint8 data);

uint8 SpiGetPolling(void);


#endif /* MCAL_SPI_INC_SPI_H_ */
