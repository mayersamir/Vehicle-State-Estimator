/*
 * MTIMER0_LConfiguration.c
 *
 *  Created on: Nov 4, 2019
 *      Author: AVE-LAP-070
 */



#include "../../../Libraries/LIBRARIES_INCLUDES/LTYPES.h"
#include "../../../Libraries/LIBRARIES_INCLUDES/LUTILS.h"
#include "TimerLcfg.h"
#include "Timer.h"



timerCfg timerPostCfgStruct = {MTIMER0_NORMAL,MTIMER0_POLLING,MTIMER0_PRESCALER1024,POSTLINKING};

timerCfg timerPostCfgStruct2 = {TIMER1_PHASE_ICR1,TIMER1_POLLING,TIMER1_PRESCALER1024,PRELINKING};



