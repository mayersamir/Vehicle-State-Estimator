/*
 * PcCommunication.h
 *
 *  Created on: Nov 13, 2019
 *      Author: AVE-LAP-070
 */

#ifndef PCCOMMUNICATION_H_
#define PCCOMMUNICATION_H_


void pcCommunicationInit(void);

void setInitialValues(void);

uint8 getInitStatus(void);
void updateSpeed(void);

#define UPCOUNTING  1
#define DOWNCOUNTING 0


#endif /* PCCOMMUNICATION_H_ */
