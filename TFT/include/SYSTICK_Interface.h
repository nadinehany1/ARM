#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


void STK_voidInt();
void STK_voidSetBadyWait(u32 Copy_u32Tick);
void STK_voidSetIntervalSignal(u32 Copy_u32Tick,void(*Copy_ptr)(void));
void STK_voidSetIntervalPeriodic(u32 Copy_u32Tick,void(*Copy_ptr)(void));
void STK_voidStopInterval(void);
u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemaningTime(void);



#endif
