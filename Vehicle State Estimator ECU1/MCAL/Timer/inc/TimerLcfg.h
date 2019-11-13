/*
 * MTIMER0_LConfiguration.h
 *
 *  Created on: Nov 4, 2019
 *      Author: AVE-LAP-070
 */

#ifndef MCAL_TIMER_INC_TIMERLCFG_H_
#define MCAL_TIMER_INC_TIMERLCFG_H_

#define PRELINKING  0
#define POSTLINKING 1

typedef struct timercfg
{

	uint8 mode;
	uint8 interruptMode;
	uint8 linkingType;
	uint16 countValue;

}timerCfg;




extern timerCfg timerPostCfgStruct;

extern timerCfg timerPostCfgStruct2;



#endif /* MCAL_TIMER_INC_TIMERLCFG_H_ */
