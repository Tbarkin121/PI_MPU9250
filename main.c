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

void test_fun(void) {
    printf("test 1 \n");
}
// void test2(void) {
//     printf("test 2 \n");
// }

int main(void)
{
	test_fun();

	inv_error_t result;
    unsigned char accel_fsr,  new_temp = 0;
    unsigned short gyro_rate, gyro_fsr;
    unsigned long timestamp;
    struct int_param_s int_param;

	result = mpu_init(&int_param);
 	if (result) {
    	MPL_LOGE("Could not initialize gyro.\n");
	}
}
