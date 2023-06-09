/*
 * NVIC_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void NVIC_voidEnablePerInt(u8 Copy_u8IntId);
void NVIC_voidDisablePerInt(u8 Copy_u8IntId);
void NVIC_voidSetPendingFlag(u8 Copy_u8IntId);
void NVIC_voidClearPendingFlag(u8 Copy_u8IntId);
void NVIC_voidGetPendingflag(u8 Copy_u8IntId);

void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOptions);
void NVIC_voidGetPriority(u8 Copy_u8IntId, u8 Copy_u8PriorityOptions);

#define GROUP_4_BITS_SUB_BITS_0_BITS		0b010
#define GROUP_3_BITS_SUB_BITS_1_BITS		0b100
#define GROUP_2_BITS_SUB_BITS_2_BITS		0b101
#define GROUP_1_BITS_SUB_BITS_3_BITS		0b110
#define GROUP_0_BITS_SUB_BITS_4_BITS		0b111

#endif /* NVIC_INTERFACE_H_ */
