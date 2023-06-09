#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "HLED_MATRIX_Interface.h"

u8 GLOB_u8DataArr[8] = {12, 18, 34, 68, 68, 34, 18, 12};   //{0, 127, 73, 73, 65, 0, 0, 0} ;
//u8 Data_Array_0[8] = {255, 2, 4, 8, 16, 32, 64, 255};//column
u8 Data_array_1[8] = {255, 2, 4, 8, 16, 32, 64, 255};//rows
u8 Data_array_2[8] = {0, 0, 255, 9, 9, 255, 0, 0};//rows
u8 Data_array_3[8] = {0, 0, 255, 9, 9, 255, 0, 0};//rows
u8 Data_array_4[8] = {255, 129, 66, 36, 24, 1, 255, 1};//rows
u8 Data_array_5[8] = {255, 2, 4, 8, 16, 32, 64, 255};//rows
u8 Data_array_6[8] = {255, 137, 137, 137, 137, 137, 0, 0};//rows

u8 Hamoksha[8] = {0, 16, 215, 255, 215, 16, 0, 2};


u8 Data_Array_0[8]={{255, 2, 4, 8, 16, 32, 64, 255},{0, 0, 255, 9, 9, 255, 0, 0},{255, 129, 66, 36, 24, 1, 255, 1},{255, 2, 4, 8, 16, 32, 64, 255},{255, 137, 137, 137, 137, 137, 0, 0}};
u8 fgh[8]={0, 0, 255, 9, 9, 255, 0, 0};

void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOA);

	/*Step 3 : Enable GPIO Peripherial Clock For Port B*/
    MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOB);

	/*Step 4 : Initialize For LED Matrix*/
    HLEDMAT_voidInit() ;


    HLEDMAT_voidDisplay(Hamoksha);

	/* Loop forever */
	while(1)
	{
//		HLEDMAT_voidDisplay(Data_array_1);
//		MSTK_voidDelayMs(1000000);
//		HLEDMAT_voidDisplay(Data_array_2);
//		MSTK_voidDelayMs(1000000);






//		HLEDMAT_voidDisplay(Data_array_1);

      /*Send Data To Led Matrix*/
//		for(u8 i=0; i<6;i++)
//		{
//			HLEDMAT_voidDisplay(Data_Array_0[i]);
//			MSTK_voidDelayMs(2500);
//		}
//		HLEDMAT_voidDisplay(Data_Array_0);
	}

}

