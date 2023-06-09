#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_Interface.h"
#include "STK_Interface.h"
#include "GPIO_Interface.h"


int main(void)
{
	RCC_voidInitSysClk();
	STK_voidInit();
	RCC_voidEnablePeriphral(AHB1,0);

	GPIO_voidSetPinOutputConfig(GPIOA,PIN0,OUTPUT_PP,OUTPUT_LS);

	GPIO_voidSetPinValue(GPIOA,PIN0,HIGH);
	STK_voidDelayMs(1000);
	GPIO_voidSetPinValue(GPIOA,PIN0,LOW);
	STK_voidDelayMs(1000);

	while(1)
	{
//		GPIO_voidSetPinValue(GPIOA,PIN0,HIGH);
//		STK_voidDelayMs(1000);
//		GPIO_voidSetPinValue(GPIOA,PIN0,LOW);
//		STK_voidDelayMs(1000);
	}
	return 0;
}
