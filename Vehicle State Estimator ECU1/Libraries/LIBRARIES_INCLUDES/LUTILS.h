/*
 * Utils.h
 *
 *  Created on: Oct 21, 2019
 *      Author: AVE-LAP-070
 */

#ifndef LUTILS_H_
#define LUTILS_H_






#define SET_BIT(REG , BIT)	REG |= (1<<BIT)
#define CLEAR_BIT(REG , BIT) REG &= ~(1<<BIT)
#define GET_BIT(REG  , BIT) ((REG >> BIT)&1)
#define TOGGLE_BIT (REG , BIT) REG ^=(1<<BIT)
#define SET_REG(REG) (REG |= 0xFF)
#define CLEAR_REG(REG) (REG &= 0x00)
#define SET_VALUE_REG(REG , value) (REG = value)
#define SET_VALUE_REG_HIGH_4bit(REG , value) (REG = (value & (0b11110000))|(REG & 0b00001111))
#define SET_4_LOW_NIPPLE(REG) (REG|=0x0F)
#define SET_4_HIGH_NIPPLE(REG) (REG|=0xF0)
#define CLEAR_4_LOW_NIPPLE(REG) (REG&=0xF0)
#define CLEAR_4_HIGH_NIPPLE(REG) (REG&=0x0F)
#define Get_4_LOW_NIBBLE(REG) (REG & 0x0F)
#define Get_4_HIGH_NIBBLE(REG) (REG & 0xF0)

#define SET_PINS_VALUE(REG,BITS) (REG|=BITS)

#define CLR_PINS_VALUE(REG,BITS) (REG&=(~BITS))

#define TOGGLE_PINS(REG,BITS)    (REG^=BITS)

#define TOGGLE_LOWER_NIBBLE(REG) (REG^=0xF0)

#define TOGGLE_HIGH_NIBBLE(REG)   (REG^=0x0F)



#endif /* UTILS_H_ */
