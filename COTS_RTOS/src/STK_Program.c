/*******************************************************************************************************/
/* Author            : Nadine Hany                                                               */
/* Version           : V0.0.0                                                                          */
/* Data              : 18  Aug 2022                                                                    */
/* Description       : MMSTK_Program.c --> implementations                                             */
/* Module  Features  : 1- MSTK_voidInit()                                                              */
/*                     2- MSTK_voidStart()                                                             */
/*                     3- MSTK_voidDelayMs()                                                           */
/*                     4- MSTK_voidDelayUs()                                                           */
/*                     5- MSTK_u8ReadFlag()                                                            */
/*                     6- MSTK_voidCtrlIntState()                                                      */
/* Future  Updates   :  interrupt handling                                                             */
/*******************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_Private.h"
#include "STK_Interface.h"
#include "STK_Config.h"

/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- STK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/



void STK_voidInit(void)
{

	/* Disable Systick Interrupt - Stop Systick - CLOCK Source = AHB / 8 */
	STK->CTRL = 0x00000000 ;   //Clr_ALL_BITS(MSTK->CTRL) ;


}
/*******************************************************************************************************/
/*                                      02- STK_voidStart                                             */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void STK_voidStart(u32 Copy_u32PreloadValue)
{

	/*Clock Source -> HSI = 16 MHz -> AHB = 16MHz -> STK Clock Source = AHB / 8 ->  2MHz
	 * 2 MicroSecond For Each Count */

	/*Load Reload Value*/
	STK->LOAD = Copy_u32PreloadValue ;

	/*Clear val Register*/
	STK->VAL  = 0 ;

	/*Enable Systick*/
	SET_BIT(STK->CTRL,STK_ENABLE_BIT);

}
/*******************************************************************************************************/
/*                                      03- STK_voidDelayMs                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void STK_voidDelayMs(u32 Copy_u32DelayMs)
{

	/*Disable Interupt*/
	STK_voidInit() ;      //function call
	STK_voidCtrlIntState(STK_INT_DISABLE) ;
	STK_voidStart(Copy_u32DelayMs) ;
	/*wait flag Polling*/
	while(STK_u8ReadFlag() == 0) ;

}
/*******************************************************************************************************/
/*                                      04- STK_voidDelayUs                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void STK_voidDelayUs(u32 Copy_u32DelayUs)
{
	if(Copy_u32DelayUs >= 2)
	{
		/*Disable Interrupt*/
		STK_voidInit() ;
		STK_voidCtrlIntState(STK_INT_DISABLE) ;
		STK_voidStart(Copy_u32DelayUs * 2) ;
		/*wait flag Polling*/
		while(STK_u8ReadFlag() == 0) ;
	}

}
/*******************************************************************************************************/
/*                                      05- MSTK_u8ReadFlag                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
u8 STK_u8ReadFlag(void)
{
	return (GET_BIT(STK->CTRL , 16)) ;
}
/*******************************************************************************************************/
/*                                      06- MSTK_voidCtrlIntState                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void STK_voidCtrlIntState(u8 Copy_u8IntStatus)
{

	//   if(Copy_u8IntStatus == MSTK_INT_ENABLE)
	//   {
	//	   SET_BIT(MSTK->CTRL,1) ;
	//   }
	//   else
	//   {
	//	   CLR_BIT(MSTK->CTRL,1) ;
	//   }

	STK->CTRL &= ~(1<<1) ;
	STK->CTRL |= (Copy_u8IntStatus << 1 ) ;
}
//
//void STK_voidCtrlIntState(u8 Copy_u8IntStatuse)
//{
//	STK -> CTRL &= ~(1<<1);
//	STK -> CTRL |= (Copy_u8IntStatuse<<1);
//}
//
//void STK_voidCallBack(void (*Fptr)(void))
//{
//	STK_voidCallBack = Fptr;
//}
//
//void SysTick_Handeler(void)
//{
//	volatile u8 Local_u8Temp = 0;
//	STK_voidCallBack();
//
//	Local_u8Temp = STK_u8ReadFlag();
//}
/*#####################################################################################################*/
/*                                       END OF PROGRAM FILE                                           */
/*#####################################################################################################*/
