/*******************************************************************************************************/
/* Author            : Nadine Hany                                                            */
/* Version           : V0.0.0                                                                          */
/* Data              : 18 Aug 2022                                                                     */
/* Description       : MSTK_Privite.h --> Register Definitions                                         */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/

#ifndef STK_REG_H_
#define STK_REG_H_


/*******************************************************************************************************/
/*                                    Macros Base Address Of  STK Registers                            */
/*******************************************************************************************************/
 
 #define    STK_BASE_ADRESS        0xE000E010

/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*-----------------------------------------------------------------------------------------------------*/
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Definition		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	NO                                                                 */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	YES                                                                */
/*                                                                                                     */
/*******************************************************************************************************/


typedef struct{

	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL  ;
	volatile u32 CALIB;

}STK;



#define STK ((volatile STK*)STK_BASE_ADRESS)


#endif /* STK_REG_H_ */
