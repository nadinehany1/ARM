/*******************************************************************************************************/

/* Author            : Nadine Hany                                                            */
/* Version           : V0.0.0                                                                          */
/* Data              : 18 Aug 2022                                                                     */
/* Description       : MSTK_Interface.c --> Function Prototypes                                        */
/* Module  Features  : 1- MSTK_voidInit()                                                              */
/*                     2- MSTK_voidStart()                                                             */
/*                     3- MSTK_voidDelayMs()                                                           */
/*                     4- MSTK_voidDelayUs()                                                           */
/*                     5- MSTK_u8ReadFlag()                                                            */
/*                     6- MSTK_voidCtrlIntState()                                                      */
/* Future  Updates   :  interrupt handling                                                             */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*	* What i sell To Customer                                                                          */
/*		*  The Architect Give The API	                                                               */
/*						- The Name Of Function                                                         */
/*						- What is The Input                                                            */
/*						- What Is The Output                                                           */
/*						- Macro                                                                        */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_



#define STK_INT_ENABLE         1
#define STK_INT_DISABLE        0



#define STK_ENABLE_BIT         0

/*#####################################################################################################*/
/*                                      Function Prototypes                                            */
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */                    
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/



void STK_voidInit(void)                                   ;
/*******************************************************************************************************/
/*                                      02- MSTK_voidStart                                             */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void STK_voidStart(u32 Copy_u32PreloadValue)              ;
/*******************************************************************************************************/
/*                                      03- MSTK_voidDelayMs                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void STK_voidDelayMs(u32 Copy_u32DelayMs)                 ;
/*******************************************************************************************************/
/*                                      04- MSTK_voidDelayUs                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void STK_voidDelayUs(u32 Copy_u32DelayUs)                 ;
/*******************************************************************************************************/
/*                                      05- MSTK_u8ReadFlag                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
u8 STK_u8ReadFlag(void)                                   ;
/*******************************************************************************************************/
/*                                      06- MSTK_voidCtrlIntState                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void STK_voidCtrlIntState(u8 Copy_u8IntStatus)            ;

void STK_voidCtrlIntState(u8 Copy_u8IntStatuse);

/*#####################################################################################################*/
/*                                     END OF INTERFACE FILE                                           */
/*#####################################################################################################*/


#endif /* STK_INTERFACE_H_ */
