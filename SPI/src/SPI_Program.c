/*
 * SPI_Program.c
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_Interface.h"
#include "SPI_Config.h"
#include "SPI_Private.h"

void (*SPI1_CallBack) (void);

void SPI_voidInit(void)
{
#if(0)
#if   SP1_STATUS == SPI_ENABLE

#if		SPI1_CLOCK_MODE == SPI_MODE0

	CLR_BIT( SPI1 -> CR1 , 0 );
	CLR_BIT( SPI1 -> CR1 , 1 );



	SET_BIT( SPI1 -> CR1 , 0 );
	CLR_BIT( SPI1 -> CR1 , 1 );

#elif	SPI1_CLOCK_MODE == SPI_MODE2

	CLR_BIT( SPI1 -> CR1 , 0 );
	SET_BIT( SPI1 -> CR1 , 1 );

#elif	SPI1_CLOCK_MODE == SPI_MODE3

	SET_BIT( SPI1 -> CR1 , 0 );
	SET_BIT( SPI1 -> CR1 , 1 );

#endif

#if    SPI1_MASTER_SLAVE == SPI_MASTER

	SET_BIT( SPI1 -> CR1 , 2 );

#elif  SPI1_MASTER_SLAVE == SPI_SLAVE

	CLR_BIT( SPI1 -> CR1 , 2 );

#endif

#if   SPI1_DATA_ORDER == SPI_MSB_FIRST

	CLR_BIT( SPI1 -> CR1 , 7 );

#elif SPI1_DATA_ORDER == SPI_LSB_FIRST

	SET_BIT( SPI1 -> CR1 , 7 );

#endif

#if   SPI1_SS_MANAGE  == HW_SLAVE_MANAGEMENT

	CLR_BIT( SPI1 -> CR1 , 9 );

#elif SPI1_SS_MANAGEb == SW_SLAVE_MANAGEMENT

	SET_BIT( SPI1 -> CR1 , 9 );

#endif

#if   SPI1_DATA_SIZE == SPI_8BIT_DATA

	CLR_BIT( SPI1 -> CR1 , 11 );

#elif SPI1_DATA_SIZE == MSPI_16BIT_DATA

	SET_BIT( SPI1 -> CR1 , 11 );

#endif

#if   SPI1_INT_STATUS == SPI_INT_DISABLE

	SPI1 -> CR2 = 0 ;

#elif SPI1_INT_STATUS == SPI_TXE_INT_ENABLE

	SET_BIT( SPI1 -> CR2 , 7 );

#elif SPI1_INT_STATUS == SPI_RXNE_INT_ENABLE

	SET_BIT( SPI1 -> CR2 , 6 );

#endif

	SPI1 -> CR1 &= 0xFFC7 ;
	MSPI1 -> CR1 |= ( MSPI1_PRESCALLER << 3 ) ;

	SET_BIT( MSPI1 -> CR1 , 6 );

#elif MSP1_STATUS == MSPI_DISABLE
	CLR_BIT( MSPI1 -> CR1 , 6 );
#endif
#endif
	SET_BIT( SPI1 -> CR1 , 9 );
	SET_BIT( SPI1 -> CR1 , 0 );
	SET_BIT( SPI1 -> CR1 , 1 );
	SET_BIT( SPI1 -> CR1 , 8 );
	SET_BIT( SPI1 -> CR1 , 2 );
	SET_BIT( SPI1 -> CR1 , 6 );

	//MSPI1 ->CR1 = 0x0000026f   ;
	//MSPI1 ->CR2 = 0x00000004   ;
}
u8 SPI_voidSendData(u8 Copy_u8Data)
{
	SPI1 -> DR = Copy_u8Data;

	while ( GET_BIT( SPI1 -> SR , 7) == 1 );

	return (u8) SPI1 -> DR ;
}
void SPI_voidSetCallBack(void (*ptr)(void))
{
	SPI1_CallBack = ptr;
}

void SPI1_IRQHandler(void)
{
	SPI1_CallBack();
}


