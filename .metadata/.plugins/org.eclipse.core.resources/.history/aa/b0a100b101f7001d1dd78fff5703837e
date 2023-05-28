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
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"


/*******************************************************************************************************/
/*                                      HAL Components                                                */
/*******************************************************************************************************/
#include "HLED_MATRIX_Interface.h"
#include "HLED_MATRIX_Config.h"
#include "HLED_MATRIX_Private.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/



void HLEDMAT_voidInit(void)
{
	/*Set Mode For Row --> Output*/
	MGPIO_voidSetPinMode(HLEDMAT_ROW0,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_ROW1,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_ROW2,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_ROW3,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_ROW4,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_ROW5,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_ROW6,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_ROW7,MGPIO_MODE_OUTPUT) ;

	/*Set Mode For Col --> Output*/
	MGPIO_voidSetPinMode(HLEDMAT_COL0,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL1,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL2,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL3,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL4,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL5,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL6,MGPIO_MODE_OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL7,MGPIO_MODE_OUTPUT) ;

	/*Set PushPull For Rows*/
	MGPIO_voidSetOutputType(HLEDMAT_ROW0,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW1,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW2,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW3,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW4,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW5,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW6,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW7,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;

	/*Set PushPull For Col */
	MGPIO_voidSetOutputType(HLEDMAT_COL0,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL1,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL2,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL3,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL4,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL5,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL6,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL7,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;

	/*Set Pin Speed ForRows*/
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW0,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW1,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW2,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW3,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW4,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW5,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW6,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW7,MGPIO_OUTPUT_SPEED_MEDUIM) ;

	/*Set Pin Speed For Col */
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL0,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL1,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL2,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL3,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL4,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL5,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL6,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL7,MGPIO_OUTPUT_SPEED_MEDUIM) ;

}

void HLEDMAT_voidDisplay(u8 *Copy_u8Frame)
{
	/*Column 0*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[0]) ;
	/*Enable Column0 */
	MGPIO_voidSetPinValue(HLEDMAT_COL0,MGPIO_LOW) ;
	//Delay 1042 us
	MSTK_voidDelayUs(2500) ; //2.5ms

	/*Column 1*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[1]) ;
	/*Enable Column0 */
	MGPIO_voidSetPinValue(HLEDMAT_COL1,MGPIO_LOW) ;
	//Delay 1042 us
	MSTK_voidDelayUs(2500) ; //2.5ms

	/*Column 2*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[2]) ;
	/*Enable Column0 */
	MGPIO_voidSetPinValue(HLEDMAT_COL2,MGPIO_LOW) ;
	//Delay 1042 us
	MSTK_voidDelayUs(2500) ; //2.5ms

	/*Column 3*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[3]) ;
	/*Enable Column0 */
	MGPIO_voidSetPinValue(HLEDMAT_COL3,MGPIO_LOW) ;
	//Delay 1042 us
	MSTK_voidDelayUs(2500) ; //2.5ms

	/*Column 4*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[4]) ;
	/*Enable Column0 */
	MGPIO_voidSetPinValue(HLEDMAT_COL4,MGPIO_LOW) ;
	//Delay 1042 us
	MSTK_voidDelayUs(2500) ; //2.5ms

	/*Column 5*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[5]) ;
	/*Enable Column0 */
	MGPIO_voidSetPinValue(HLEDMAT_COL5,MGPIO_LOW) ;
	//Delay 1042 us
	MSTK_voidDelayUs(2500) ; //2.5ms


	/*Column 6*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[6]) ;
	/*Enable Column0 */
	MGPIO_voidSetPinValue(HLEDMAT_COL6,MGPIO_LOW) ;
	//Delay 1042 us
	MSTK_voidDelayUs(2500) ; //2.5ms

	/*Column 7*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[7]) ;
	/*Enable Column0 */
	MGPIO_voidSetPinValue(HLEDMAT_COL7,MGPIO_LOW) ;
	//Delay 1042 us
	MSTK_voidDelayUs(2500) ; //2.5ms

}


static void HLEDMAT_voidDisableCols(void)
{
	MGPIO_voidSetPinValue(HLEDMAT_COL0,MGPIO_HIGH) ;
	MGPIO_voidSetPinValue(HLEDMAT_COL1,MGPIO_HIGH) ;
	MGPIO_voidSetPinValue(HLEDMAT_COL2,MGPIO_HIGH) ;
	MGPIO_voidSetPinValue(HLEDMAT_COL3,MGPIO_HIGH) ;
	MGPIO_voidSetPinValue(HLEDMAT_COL4,MGPIO_HIGH) ;
	MGPIO_voidSetPinValue(HLEDMAT_COL5,MGPIO_HIGH) ;
	MGPIO_voidSetPinValue(HLEDMAT_COL6,MGPIO_HIGH) ;
	MGPIO_voidSetPinValue(HLEDMAT_COL7,MGPIO_HIGH) ;
}

static void HLEDMAT_voidSetRowVlaues(u8 Copy_u8Frame)
{
	MGPIO_voidSetPinValue(HLEDMAT_ROW0,GET_BIT(Copy_u8Frame,0)) ;
	MGPIO_voidSetPinValue(HLEDMAT_ROW1,GET_BIT(Copy_u8Frame,1)) ;
	MGPIO_voidSetPinValue(HLEDMAT_ROW2,GET_BIT(Copy_u8Frame,2)) ;
	MGPIO_voidSetPinValue(HLEDMAT_ROW3,GET_BIT(Copy_u8Frame,3)) ;
	MGPIO_voidSetPinValue(HLEDMAT_ROW4,GET_BIT(Copy_u8Frame,4)) ;
	MGPIO_voidSetPinValue(HLEDMAT_ROW5,GET_BIT(Copy_u8Frame,5)) ;
	MGPIO_voidSetPinValue(HLEDMAT_ROW6,GET_BIT(Copy_u8Frame,6)) ;
	MGPIO_voidSetPinValue(HLEDMAT_ROW7,GET_BIT(Copy_u8Frame,7)) ;
}

