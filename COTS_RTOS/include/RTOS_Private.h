/*
 * RTOS_Private.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	void (*PF)(void);
	u32 First_Delay;
	u32 Pirodicity;
}TCB;
//
//TCB_t Task_Arr[No_Of_Tasks] = {NULL};
//
//static void RTOS_Sceduler(void);

#define No_Of_Tasks 			10
#endif /* RTOS_PRIVATE_H_ */
