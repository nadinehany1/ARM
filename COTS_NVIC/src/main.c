#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"

#include "NVIC_Interface.h"
#include "STK_Interface.h"

//void SysTick_Handeler(void);
void AppDelay(void);
int main(void)
{
	RCC_voidInitSysClk();
	//STK_voidInit();
	RCC_voidEnablePeriphral(AHB1,0);
	GPIO_voidSetPinOutputConfig(GPIOA,PIN1,OUTPUT_PP,OUTPUT_LS);
	NVIC_voidEnablePerInt(6);
	NVIC_voidSetPendingFlag(6);
	GPIO_voidSetPinValue(GPIOA,PIN1,SET);
//	GPIO_voidSetPinValue(GPIOA,PIN1,HIGH);

	while(1)
	{
		NVIC_voidSetPendingFlag(6);
		//GPIO_voidDirectSetResetPinValue(GPIOA,PIN1,RST);
//		__asm ("NOP");
//		GPIO_voidDirectSetResetPinValue(GPIOA,PIN1,SET);
//		STK_voidSetBusyWait(500);
//		GPIO_voidDirectSetResetPinValue(GPIOA,PIN1,RST);
//		STK_voidSetBusyWait(500);

	}
	return 0;
}


void EXTI0_IRQHandler(void)
{
	GPIO_voidDirectSetResetPinValue(GPIOA, PIN1, SET);
	AppDelay();
	//STK_voidSetBusyWait(500);
	GPIO_voidDirectSetResetPinValue(GPIOA, PIN1, RST);
	AppDelay();
	//STK_voidSetBusyWait(500);
}


void AppDelay(void)
{
	u32 i;
	for (i =0 ; i < 5000 ; i++)
	{
		__asm("NOP");
	}
}
