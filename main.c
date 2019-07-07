/**
 *   @defgroup  eMPL
 *   @brief     Embedded Motion Processing Library
 *
 *   @{
 *       @file      main.c
 *       @brief     Test app for eMPL using the Motion Driver DMP image.
 */
 
/* Includes ------------------------------------------------------------------*/
#include "stdio.h"

#include "main.h"
#include "inv_mpu.h"

#define maintest2 test2

void test(void) {
    printf("test 1 \n");
}
// void test2(void) {
//     printf("test 2 \n");
// }

int main(void)
{
	test();
	test2();
	maintest2();
	// printf('%d',test());
}
