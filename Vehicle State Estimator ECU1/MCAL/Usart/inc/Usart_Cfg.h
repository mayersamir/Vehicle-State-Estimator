/*
 * Usart_Cfg.h
 *
 *  Created on: Nov 10, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_USART_INC_USART_CFG_H_
#define MCAL_USART_INC_USART_CFG_H_

/*
 *
 * this file specially for pre compilation configuration !!!
 * change this file only if you want to mess with the pre-configuration
 */


#define        USART_MODE              USART_ASYNCHRONOUS_MODE

#define        USART_CFG_MODE          USART_RECEIVER_TRANSMITTER_CFG

#define        USART_PARITY            USART_PARITY_DISABLED

#define        USART_STOP_BITS         USART_1BIT_STOP

#define        USART_DATA_FRAME_BITS   USART_8BIT_DATA

#define        USART_POLARITY          USART_RTRANSMIT_FRECEIVE

#define        USART_INTERRUPT_CFG     USART_POLLING_VALUE

#define        USART_BAUDRATE          BAUD2


#endif /* MCAL_USART_INC_USART_CFG_H_ */
