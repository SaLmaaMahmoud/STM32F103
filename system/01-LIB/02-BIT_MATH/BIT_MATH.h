/************************************************/
/* Author	: Salma Mahmoud						*/
/* Date 	: 21 OCT 2022						*/
/* Version 	: V01								*/
/************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT) 	(REG |= (1 << BIT))
#define CLR_BIT(REG,BIT)	(REG &= ~(1 << BIT))
#define TOGGLE_BIT(REG,BIT) (REG ^= (1 << BIT))
#define CLR_REG(REG) 		(REG &= ~(255 << 0))
#define SET_REG(REG) 		(REG |= ~(255 << 0))
#define IS_SET(REG,BIT) 	(REG & (1 << BIT))
#define GET_BIT(REG,BIT) 	((REG>>BIT)&1)

#endif

