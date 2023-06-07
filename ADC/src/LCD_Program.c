 #include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "../MCAL/DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"



/*  3 func :Init , SendCommand , SendChar*/
void LCD_voidInit(void)
{
   /*configration of lcd control pins direction as output  */
   DIO_voidSetPinDirection( LCD_CR , RS_PIN, OUTPUT);    // RS direction is o/p
   DIO_voidSetPinDirection( LCD_CR , RW_PIN, OUTPUT);    // RW direction is o/p
   DIO_voidSetPinDirection( LCD_CR , E_PIN, OUTPUT);    // E direction is o/p

   DIO_voidSetPortDirection(LCD_DR,OUTPUT);
   _delay_ms(50);

   /*send function set instruction */
   LCD_voidSendCommand(0b00111000);

   _delay_ms(2);

   /*Display on & off control*/
   LCD_voidSendCommand(0b00001100);
   _delay_ms(2);

   /*Clear Display*/
   LCD_voidSendCommand(0b00000001);
   _delay_ms(2);

   /*entry mode set control*/
   LCD_voidSendCommand(0b00000110);
   _delay_ms(2);


}



void LCD_voidSendCommand(u8 Copy_u8Command)
{
    /*RS=0  , AS we use (send command)  not data*/
    DIO_voidSetPinValue(LCD_CR, RS_PIN,LOW);

    DIO_voidSetPinValue(LCD_CR, RW_PIN,LOW);

    DIO_voidSetPortValue(LCD_DR,Copy_u8Command);
   /*Falling edge on enable pin */
   DIO_voidSetPinValue(LCD_CR,E_PIN,HIGH);
   _delay_ms(50);
   
   DIO_voidSetPinValue(LCD_CR,E_PIN,LOW);

}



// to send data char  one
void LCD_voidSendChar(u8 Copy_u8Char)
{
    /*RS=1  , AS we use (send data)  not command*/
    DIO_voidSetPinValue(LCD_CR, RS_PIN,HIGH);

    DIO_voidSetPinValue(LCD_CR, RW_PIN,LOW);

    DIO_voidSetPortValue(LCD_DR,Copy_u8Char);
   /*Falling edge on enable pin */
   DIO_voidSetPinValue(LCD_CR,E_PIN,HIGH);
   _delay_ms(50);
   
   DIO_voidSetPinValue(LCD_CR,E_PIN,LOW);
}


// to print word
void LCD_voidSendString(u8 * Copy_u8String)
{
    u8 i=0;
    while (Copy_u8String[i] != '\0')
    {
    	LCD_voidSendChar(Copy_u8String[i]);
        i++;
    }

}
// to print number
void LCD_voidSendNumber(u32 Copy_u32Num)
{
	    u8 i=0;
	    s8 j=0;
	    u8 Arr[5];
	    u8 tmp;
	    while (Copy_u32Num  > 0)
	    {
	        Arr[i]=Copy_u32Num  % 10;
	        Copy_u32Num=Copy_u32Num/10;
	        i++;
	    }
	    i--;
	    for ( j = i ; j >= 0 ; j--)
	    {
	        tmp=Arr[j]+'0';
	        LCD_voidSendChar(tmp);
	    }

}

// to clear lcd
void LCD_Clear()
{
	LCD_voidSendCommand (0x01);
	LCD_voidSendCommand (0x80);
}

// to send data to specific position
void LCD_voidGoTO_xy(u8 Copy_u8Line , u8 Copy_u8Postion)    //set position
{
    switch (Copy_u8Line)
    {
    case Line1 :
        LCD_voidSendCommand(0x80 +Copy_u8Postion +0 );
        break;
    case Line2 :
        LCD_voidSendCommand(0x80 + Copy_u8Postion + 64);
        break;

    default:
        break;
    }
}

// another function to print data
void LCD_voidCustom_Char (u8 loc, u8 *msg)
{
	u8 i;
	if(loc<8)
	{
		LCD_voidSendCommand (0x40 + (loc*8));
		for(i=0;i<8;i++)
		LCD_voidSendChar(msg[i]);
	}
}

// another function to print data at specific postion
void LCD_voidGoToPos(u8 A_u8RowNumber, u8 A_u8ColNumber)
{
 switch (A_u8RowNumber)
 {
 case ROW_ONE: LCD_voidSendCommand(LCD_ROW_1_ADDRESS + A_u8ColNumber); break;
 case ROW_TWO: LCD_voidSendCommand(LCD_ROW_2_ADDRESS + A_u8ColNumber); break;
 }
}
// to draw pattern
void LCD_voidSendSpecialPattern (u8 *A_pu8PatternArr, u8 A_u8PatternNum, u8 A_u8RowNumber, u8 A_u8ColNumber)
{
	// CGRAM address --> 0 to 63 --> need 6 bits from bit 0 to bit 5
	u8 local_u8counter = 0, local_u8CGRAMAddress = A_u8PatternNum * 8;
	SET_BIT(local_u8CGRAMAddress,6);

	//send command to set CGRAM Address
	LCD_voidSendCommand(local_u8CGRAMAddress);

	for(local_u8counter = 0; local_u8counter < 8; local_u8counter++)
	{
		//send Byte from Pattern Array
		LCD_voidSendChar(A_pu8PatternArr[local_u8counter]);
	}
	//send command to set the DDRAM Address
	LCD_voidGoToPos(A_u8RowNumber,A_u8ColNumber);

	//Display the required pattern from CGRAM
	LCD_voidSendChar(A_u8PatternNum);
}

/*==========================================*/
// anther function to send one char
void LCD_voidSaveCustomChar(u8 u8_arr[] , u8 cpy_address)
{
	if(cpy_address  < 8)
	{
		LCD_voidSendCommand(0x40 + (8*cpy_address));
	    for (u8 i =0 ; i<8 ; i++)
	    {
	    	LCD_voidSendChar(u8_arr[i]);
	    }
	    LCD_voidSendCommand(0x80);
	}
}

