/*
 * STK_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable Systick                          */
void STK_voidInit(void);
void STK_voidSetBusyWait( u32 Copy_u32Ticks );
void STK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void STK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void STK_voidStopInterval(void);
u32  STK_u32GetElapsedTime(void);
u32  STK_u32GetRemainingTime(void);





#endif /* STK_INTERFACE_H_ */
