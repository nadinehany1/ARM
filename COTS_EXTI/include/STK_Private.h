/*
 * STK_Private.h
 *
 *  Created on: 13/5/2023
 *      Author: Nadine Hany
 */

#ifndef STK_PIRIVATE_H_
#define STK_PIRIVATE_H_

//#define STK_CTRL	*((volatile u32*)(0xE000E010))
//#define STK_LOAD	*((volatile u32*)(0xE000E014))
//#define STK_VAL		*((volatile u32*)(0xE000E018))
//#define STK_CALIB	*((volatile u32*)(0xE000E01C))
typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
}STK_Type;

#define     STK    ((STK_Type*)0xE000E010)

#define STK_SRC_AHB           	0
#define STK_SRC_AHB_8        	1

#define STK_SINGLE_INTERVAL    	0
#define STK_PERIOD_INTERVAL    	1


#endif /* STK_PIRIVATE_H_ */
