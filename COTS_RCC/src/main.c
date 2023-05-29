#include <BIT_MATH.h>
#include <STD_TYPES.h>

#include "RCC_Program.c"

void App_voidDelayMS(u32 Copy_32Delay);

#define GPIOA_MODER	   (*((volatile u32*)(0x40020000)))//input or output

#define GPIOA_ODR	   (*((volatile u32*)(0x40020014)))//high or low

void main(void)
{
	/*system clock is 25 MHz from HSE*/
	RCC_voidInitSysClk();
	/*enable gpio perpherial clock for port a*/
	RCC_voidEnablePeriphral(AHB1, 0);
	/*configure pin A0 as output pin*/
	SET_BIT(GPIOA_MODER,0);
	SET_BIT(GPIOA_ODR,0);

	while(1)
	{
		CLR_BIT(GPIOA_ODR,0);
		App_voidDelayMS(10000);
		SET_BIT(GPIOA_ODR,0);
		App_voidDelayMS(10000);
	}


}

void App_voidDelayMS(u32 Copy_32Delay)
{
	for(u32 i=0; i<Copy_32Delay*300;i++)
	{
		asm("NOP");
	}
}
