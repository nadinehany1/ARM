/*
 * TFT_Program.c
 *
 *  Created on: 3/6/2023
 *      Author: Nadine Hany
 */

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

#include "MRCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"

#include "TFT_Interface.h"
#include "TFT_Config.h"
#include "TFT_Private.h"


void TFT_SendCommand(u8 Copy_u8Command)
{
	/*Set Pin A0 to Low*/
	GPIO_voidSetPinValueNonAtumic(GPPIOA,);
}

void TFT_SendData(u8 Copy_u8Data)
{
	GPIO_voidSetPinValueNonAtumic()
}

void Reset()
{
	GPIO_voidSetPinValueNonAtumic(TFT_RST_PIN,HIGH);
	STK_voidSetBadyWait(10);
	GPIO_voidSetPinValueNonAtumic(TFT_RST_PIN,LOW);
	STK_voidSetBadyWait(1);
	GPIO_voidSetPinValueNonAtumic(TFT_RST_PIN,HIGH);
	STK_voidSetBadyWait(10);
	GPIO_voidSetPinValueNonAtumic(TFT_RST_PIN,LOW);
	STK_voidSetBadyWait(10);
	GPIO_voidSetPinValueNonAtumic(TFT_RST_PIN,HIGH);
	STK_voidSetBadyWait(12);
}

void TFT_Init()
{
	Reset();

	TFT_SendCommand(0x11);
	//Wait 150 micro
	STK_voidSetBadyWait(150);

	TFT_SendCommand(0x3A);

	//RGB 565
	TFT_SendData(0x05);
	//Display Command
	TFT_SendCommand(0x29);

}

void TFT_voidDisplayImage(const u16* Copy_ptrImage)
{
	u16 Data;
	//Set X Address
	TFT_SendCommand(0x2A);

	//Start
	TFT_SendData(0);
	TFT_SendData(0);
	//Stop
	TFT_SendData(0);
	TFT_SendData(127);

	//Set Y Address
	TFT_SendCommand(0x2B);

	//Start
	TFT_SendData(0);
	TFT_SendData(0);
	//Stop
	TFT_SendData(0);
	TFT_SendData(159);

	//
	TFT_SendCommand(0x2C);

	//Display
	for(u16 Local_u16Count =0 ; Local_u16Count <20480 ; Local_u16Count ++)
	{
		Data = Copy_ptrImage[Local_u16Count] >> 8;
		TFT_SendData(Data);
		Data = (u8)Copy_ptrImage[Local_u16Count];
		TFT_SendData(Data);
	}
}
