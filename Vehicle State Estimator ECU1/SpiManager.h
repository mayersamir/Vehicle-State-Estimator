/*
 * SpiManager.h
 *
 *  Created on: Nov 12, 2019
 *      Author: AVE-LAP-070
 */

#ifndef SPIMANAGER_H_
#define SPIMANAGER_H_

#define NUMBER_OF_SLAVES   1
#define CFG_PORT      PORTB

#define SLAVE_SELECT_PIN   BIT4
#define MOSI               BIT5
#define MISO               BIT6
#define SPI_CLK            BIT7


#define SEND               0
#define RECEIVE            1



void SpiManipulateMode(uint8 spiMode);
uint8 SpiSendData(uint8 data,uint8 flag);


#endif /* SPIMANAGER_H_ */
