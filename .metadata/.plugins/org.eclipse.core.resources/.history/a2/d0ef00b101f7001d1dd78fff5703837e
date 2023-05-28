#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "HLED_MATRIX_Interface.h"

u8 GLOB_u8DataArr[8] = {28, 34, 66, 68, 66, 34, 28, 0};//{0, 127, 73, 73, 65, 0, 0, 0} ;

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

	/* Loop forever */
	while(1)
	{
      /*Send Data To Led Matrix*/
		HLEDMAT_voidDisplay(GLOB_u8DataArr) ;
	}

}

