/*
 * communication.h
 *
 * Created: 11/13/2019 2:01:45 PM
 *  Author: AVE-LAP-44
 */ 


#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

/************************************************************************/
/*                            Files Includes                            */
/************************************************************************/
#include "Typedefs.h"

/************************************************************************/
/*                       Extern Global Variables                        */
/************************************************************************/
extern volatile uint32 Time_Current;
extern volatile uint32 Time_Prev;
extern volatile uint32 Time_Init;
extern volatile uint8  Distance;


void Measurement_Init();

void Measurement_Calc();

void Measurement_Send();

#endif /* COMMUNICATION_H_ */