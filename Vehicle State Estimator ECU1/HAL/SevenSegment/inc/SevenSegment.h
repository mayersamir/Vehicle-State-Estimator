/*
 * 7SEGMENT_Interface.h
 *
 *  Created on: Oct 23, 2019
 *      Author: AVE-LAP-070
 */

#ifndef HAL_HAL_INCLUDES_7SEGMENT_INCLUDES_7SEGMENT_INTERFACE_H_
#define HAL_HAL_INCLUDES_7SEGMENT_INCLUDES_7SEGMENT_INTERFACE_H_


#define SEGMENT_ENABLE  1
#define SEGMENT_DISABLE 0


void intialize_7SEGMENT(void);

void visualizeNumber(uint8 number);

void enableSegment(uint8 segmentPort,uint8 segmentPin,uint8 segmentEnable);



#endif /* HAL_HAL_INCLUDES_7SEGMENT_INCLUDES_7SEGMENT_INTERFACE_H_ */
