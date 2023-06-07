#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"


#include "SYSTICK_Interface.h"
#include "SYSTICK_Private.h"
#include "SYSTICK_Config.h"

void (*Global_CallBack)(void);
u32 modeInterval=0;

void STK_voidInt()
{
    #if(STK_CLOCK_SOURCE==AHB)
    {
        SET_BIT(STK_CTRL,2);
    }
    #elif(STK_CLOCK_SOURCE==(AHB/8))
    {
        CLR_BIT(STK_CTRL,2);
    }
    #endif
    
}
void STK_voidSetBadyWait(u32 Copy_u32Tick)
{
	//set load register
	 STK_LOAD =Copy_u32Tick;
    //enable systick
    SET_BIT(STK_CTRL,0);

    //polling
    while(GET_BIT(STK_CTRL,16)==0);
    //stope timer
    CLR_BIT(STK_CTRL,0);
    STK_LOAD=0;
    STK_VAL =0;

}
void STK_voidSetIntervalSignal(u32 Copy_u32Tick,void(*Copy_ptr)(void))
{
    //desable timer
    CLR_BIT(STK_CTRL,0);
    //set value=0
    STK_VAL =0;
    //set load register
    STK_LOAD =Copy_u32Tick;
    //start timer
    SET_BIT(STK_CTRL,0);
    //save callback
    Global_CallBack=Copy_ptr;
    //select interval mode
    modeInterval=STK_SINGLE_INTERVAL ;
    //enable interrupte
    SET_BIT(STK_CTRL,1);

}
void STK_voidSetIntervalPeriodic(u32 Copy_u32Tick,void(*Copy_ptr)(void))
{
    //desable timer
    CLR_BIT(STK_CTRL,0);
    //set value=0
    STK_VAL =0;
    //set load register
    STK_LOAD =Copy_u32Tick;
    //start timer
    SET_BIT(STK_CTRL,0);
    //save callback
    Global_CallBack=Copy_ptr;
    //select interval mode
    modeInterval=STK_PERIODIC_INTERVAL ;
    //enable interrupte
    SET_BIT(STK_CTRL,1);
}
void STK_voidStopInterval(void)
{
    //disable interrupt
    CLR_BIT(STK_CTRL,1);
    //stop timer
    CLR_BIT(STK_CTRL,0);
    STK_LOAD=0;
    STK_VAL =0;
}
u32 STK_u32GetElapsedTime(void)
{
   u32 Local_ElapseTime;
   Local_ElapseTime=STK_LOAD - STK_VAL;
   return Local_ElapseTime;
}
u32 STK_u32GetRemaningTime(void)
{
    u32 Local_RemaningTime;
    Local_RemaningTime=STK_VAL;
   return Local_RemaningTime;
}
