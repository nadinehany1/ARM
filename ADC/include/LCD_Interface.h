#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "..\LIB\STD_TYPES.h"
#define ROW_ONE  1
#define ROW_TWO  2
#define LCD_ROW_1_ADDRESS 127
#define LCD_ROW_2_ADDRESS 191

#define Line1   0
#define Line2   1
/*  3 func :Init , SendCommand , SendChar*/

/*instruction  then   display on & off   then   clear   then entry mode*/
void LCD_voidInit(void);

/*send command*/
void LCD_voidSendCommand(u8 Copy_u8Command);

/*send character*/
void LCD_voidSendChar(u8 Copy_u8Char);
/*to write string */
void LCD_voidSendString(u8  * Copy_u8String);

/*to write number */
void LCD_voidSendNumber(u32 Copy_u32Num);
/*to clear lcd */
void LCD_Clear();
/*to go to specific position */
void LCD_voidGoTO_xy(u8 Copy_u8Line , u8 Copy_u8Postion);
/*to send character*/
void LCD_voidCustom_Char (u8 loc, u8 *msg);
void LCD_voidSaveCustomChar(u8 u8_arr[] , u8 cpy_address);



#endif 
