/*
 * HLED_MATRIX_Config.h
 *
 *  Created on: Aug 28, 2022
 *      Author: ahmed.hammad
 */

#ifndef HLED_MATRIX_CONFIG_H_
#define HLED_MATRIX_CONFIG_H_


/*Please write port,pin in pair*/


#define HLEDMAT_ROW0      MGPIOA_PORT,0
#define HLEDMAT_ROW1      MGPIOA_PORT,1
#define HLEDMAT_ROW2      MGPIOA_PORT,2
#define HLEDMAT_ROW3      MGPIOA_PORT,3
#define HLEDMAT_ROW4      MGPIOA_PORT,4
#define HLEDMAT_ROW5      MGPIOA_PORT,5
#define HLEDMAT_ROW6      MGPIOA_PORT,6
#define HLEDMAT_ROW7      MGPIOA_PORT,7

/*Please write port,pin in pair*/


#define HLEDMAT_COL0      MGPIOB_PORT,0
#define HLEDMAT_COL1      MGPIOB_PORT,1
#define HLEDMAT_COL2      MGPIOB_PORT,5     // 3 for JTAG
#define HLEDMAT_COL3      MGPIOB_PORT,6     // 4 for JTAGA
#define HLEDMAT_COL4      MGPIOB_PORT,7
#define HLEDMAT_COL5      MGPIOB_PORT,8
#define HLEDMAT_COL6      MGPIOB_PORT,9
#define HLEDMAT_COL7      MGPIOB_PORT,10



#endif /* HLED_MATRIX_CONFIG_H_ */
