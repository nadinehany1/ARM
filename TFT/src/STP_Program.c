/*
 * HLED_MATRIX_Program.c
 *
 *  Created on: Aug 28, 2022
 *      Author: ahmed.hammad
 */

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "SYSTICK_Interface.h"


/*******************************************************************************************************/
/*                                      HAL Components                                                */
/*******************************************************************************************************/
#include "STP_Interface.h"
#include "STP_Config.h"
#include "STP_Private.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/



void STP_voidInit(void)
{

	GPIO_voidSetPinMode(STP_SERIAL_DATA,OUTPUT);
	GPIO_voidSetPinMode(STP_STOR_CLOCK,OUTPUT);
	GPIO_voidSetPinMode(STP_SHIFT_CLOCK,OUTPUT);



}

void STP_voidSynchronus(u8 copy_DataToBeSent)
{
	s8 local_u8Counter;
	u8 local_u8Bit;
	for(local_u8Counter=7;local_u8Counter>=0;local_u8Counter--)
	{
		local_u8Bit=GET_BIT(copy_DataToBeSent,local_u8Counter);
		GPIO_voidSetPinValueNonAtumic(STP_SERIAL_DATA,local_u8Bit);

		//send pulse to shift clock
		GPIO_voidSetPinValueNonAtumic(STP_SHIFT_CLOCK,HIGH);
		STK_voidSetBadyWait(1);
		GPIO_voidSetPinValueNonAtumic(STP_SHIFT_CLOCK,LOW);
		STK_voidSetBadyWait(1);
	}

	//Send pulse to storge clock
	GPIO_voidSetPinValueNonAtumic(STP_STOR_CLOCK,HIGH);
	STK_voidSetBadyWait(1);
	GPIO_voidSetPinValueNonAtumic(STP_STOR_CLOCK,LOW);
	STK_voidSetBadyWait(1);




	}



