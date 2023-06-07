/*
 * TFT_Private.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef TFT_PRIVATE_H_
#define TFT_PRIVATE_H_


void TFT_SendCommand(u8 Copy_u8Command);
void TFT_SendData(u8 Copy_u8Data);


#define Control_Pin			0xff

#endif /* TFT_PRIVATE_H_ */
