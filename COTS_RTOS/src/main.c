#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_Interface.h"
#include "RCC_Interface.h"
#include "STK_Interface.h"

//#include "RTOS_Config.h"
//#include "RTOS_Interface.h"
//#include "RTOS_Private.h"
#include "FreeRTOS.h"
#include "task.h"

#include "semphr.h"

SemaphoreHandle_t Tst_semaphore;
BaseType_t Semph_State;

void Task1(void)
{
	static u8 flag = 0;
	while(1)
	{
		Semph_State = xSemaphoreTake(Tst_semaphore,1100);
		if(Semph_State==pdTRUE)
		{
			if(flag==0)
			{
				GPIO_voidSetPinValue(GPIOA,PIN0,1);
				flag=1;
			}
			else
			{
				GPIO_voidSetPinValue(GPIOA,PIN0,0);
				flag = 0;
			}
			xSemaphoreGive(Tst_semaphore);
			vTaskDelay(1000);
		}
	}
}
void Task2(void)
{
	static u8 flag = 0;
	Semph_State = xSemaphoreTake(Tst_semaphore,2100);
	if(Semph_State==pdTRUE)
	{
	while(1)
		{
			if(flag==0)
			{
				GPIO_voidSetPinValue(GPIOA,PIN1,1);
				flag=1;
			}
			else
			{
				GPIO_voidSetPinValue(GPIOA,PIN1,0);
				flag = 0;
			}
			xSemaphoreGive(Tst_semaphore);
			vTaskDelay(2000);
		}
	}
}
void Task3(void)
{
	static u8 flag = 0;
	Semph_State = xSemaphoreTake(Tst_semaphore,3100);
	{
	while(1)
	{
		if(flag==0)
		{
			GPIO_voidSetPinValue(GPIOA,PIN2,1);
			flag=1;
		}
		else
		{
			GPIO_voidSetPinValue(GPIOA,PIN2,0);
			flag = 0;
		}
		xSemaphoreGive(Tst_semaphore);
		vTaskDelay(3000);
	}
	}
}

int main()
{
	RCC_voidInitSysClk();
	RCC_voidEnablePeriphral(AHB1,0);

	GPIO_voidSetPinOutputConfig(GPIOA,PIN0,OUTPUT_PP,OUTPUT_HS);
	GPIO_voidSetPinOutputConfig(GPIOA,PIN1,OUTPUT_PP,OUTPUT_HS);
	GPIO_voidSetPinOutputConfig(GPIOA,PIN2,OUTPUT_PP,OUTPUT_HS);

	xTaskCreate(Task1,NULL,50,NULL,1,NULL);
	xTaskCreate(Task2,NULL,50,NULL,2,NULL);
	xTaskCreate(Task3,NULL,50,NULL,3,NULL);

	vTaskStartScheduler();

	vSemaphoreCreateBinary(Tst_semaphore);
	while (1)
	{
	   // Add your code here.
	}
	return 0;
}


// ----------------------------------------------------------------------------
