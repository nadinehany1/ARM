#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Configration.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"


void App_delayMs(u32 Copy_u32Delay);

int main()
{
	RCC_voidInitSysClk();

	RCC_voidEnablePeriphral(AHB1,0);

	GPIO_voidSetPinOutputConfig(GPIOA, PIN7, OUTPUT_PP, OUTPUT_HS);

	while(1)
    {
	   GPIO_voidDirectSetResetPinValue(GPIOA, PIN7, SET);
       App_delayMs(10000);
	   GPIO_voidDirectSetResetPinValue(GPIOA, PIN7, RST);
       App_delayMs(10000);
    }
}

void App_delayMs(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay*300; Local_u32Counter++)
	{
		asm("NOP");
	}
}
