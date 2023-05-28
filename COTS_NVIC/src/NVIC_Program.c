/*
 * NVIC_Program.c
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Config.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"

static u8 staticglobal_u8PeriodityConf;

void NVIC_voidEnablePerInt(u8 Copy_u8IntId)
{
	NVIC -> ISER[(Copy_u8IntId/32)] = (1<<(Copy_u8IntId%32));
}

void NVIC_voidDisablePerInt(u8 Copy_u8IntId)
{
	NVIC -> ICER[(Copy_u8IntId/32)] = (1<<(Copy_u8IntId%32));
}

void NVIC_voidSetPendingFlag(u8 Copy_u8IntId)
{
	NVIC -> ISPR[(Copy_u8IntId/32)] = (1<<(Copy_u8IntId%32));
}

void NVIC_voidClearPendingFlag(u8 Copy_u8IntId)
{
	NVIC -> ICPR[(Copy_u8IntId/32)] = (1<<(Copy_u8IntId%32));
}

void NVIC_voidGetPendingflag(u8 Copy_u8IntId)
{

}

void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOptions)
{
	staticglobal_u8PeriodityConf= VECT_KEY | (Copy_u8PriorityOptions<<8);
	SCB -> AIRCR = staticglobal_u8PeriodityConf;
}

void NVIC_voidSetIntPriority(u8 Copy_u8IntId, u8 Copy_GroupId, u8 Copy_u8SubGroup)
{
	u8 Local_u8Priority = Copy_u8SubGroup |(Copy_GroupId<<(staticglobal_u8PeriodityConf-0x05FA0300)/256);
	NVIC -> IPR [Copy_u8IntId] = (Local_u8Priority<<4);
}


