
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"

#include "SYSTICK_Interface.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Private.h"

#include "STP_Interface.h"

int main()
{
	MRCC_voidInitSystemClk();
	MRCC_voidEnablePeripheralClock(AHB1 , 0);

	STK_voidInt();
	STP_voidInit();


	while(1)
    {
	  // STP_voidSynchronus(0x55);
		for (u8 i=0;i<8;i++)
		{
			STP_voidSynchronus(1<<i);
			STK_voidSetBadyWait(300000);
		}
    }
}





