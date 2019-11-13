/*
 * LTYPES.h
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#ifndef LTYPES_H_
#define LTYPES_H_



typedef unsigned char uint8;
typedef signed char sint8;
typedef	unsigned short int uint16;
typedef signed short int sint16;
typedef unsigned long int uint32;
typedef signed long int sint32;
typedef float f32;
typedef double f64;
typedef volatile uint8* const reg_type;

typedef uint8 bool;
typedef bool STATUS;
#define E_OK (STATUS) 1
#define E_NOT_OK (STATUS) 0

#define NULL ((void *)0)


#define ZERO   0
#define ONE    1


#endif /* LTYPES_H_ */
