#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_Interface.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
#include "RCC_Interface.h"

int main()
{
	u16 Local_u16LM35, Local=0;
	ADC_voidInit();
	LCD_voidInit();
	Local=(((ADC_u16ReadSynchronus(0)*(u32)5000)/1024));
	Local_u16LM35=Local/10;

	if(Local_u16LM35>=25)
	{
		LCD_voidSendString("TEMP: ");
		LCD_voidSendString("HIGH = ");
		LCD_voidSendNum(Local);
	}
	else if(Local_u16LM35<25)
	{
		LCD_voidSendString("TEMP: ");
		LCD_voidSendString("LOW = ");
		LCD_voidSendNum(Local);
	}
	while(1)
	{

	}
}
