/*
 $License:
    Copyright (C) 2011-2012 InvenSense Corporation, All Rights Reserved.
    See included License.txt for License information.
 $
 */
/**
 *  @addtogroup  DRIVERS Sensor Driver Layer
 *  @brief       Hardware drivers to communicate with sensors via I2C.
 *
 *  @{
 *      @file       inv_mpu.c
 *      @brief      An I2C-based driver for Invensense gyroscopes.
 *      @details    This driver currently works for the following devices:
 *                  MPU6050
 *                  MPU6500
 *                  MPU9150 (or MPU6050 w/ AK8975 on the auxiliary bus)
 *                  MPU9250 (or MPU6500 w/ AK8963 on the auxiliary bus)
 */
#include "stdio.h"
#include "inv_mpu_test.h"
#include "i2c_interface.h"
#include "math.h"

#define i2c_write i2c_write_interface
#define i2c_read i2c_read_interface
#define delay_ms(a) delay_interface(a*1000)
#define get_ms gpioTick_interface
//#define log_i(...)     do {} while (0)
//#define log_e(...)     do {} while (0)
#define log_i       printf
#define log_e       printf

#define min(a,b) ((a<b)?a:b)

void test2(void) {
	printf("test 2 \n");
	unsigned char data_write[2];
	unsigned char data_read[2];
	data_write[0] = 0x30;
	data_write[1] = 0x40;

	i2c_write(0x68, 0x00, 2, data_write);
	i2c_read(0x68, 0x00, 2, data_read);
	printf("Data Write: %x, %x \n",data_write[0],data_write[1]);
	printf("Data Read: %x, %x \n",data_read[0],data_read[1]);
	for(int i = 0; i<5; i++){
		delay_ms(1000);
		printf("was that about a second? \n");
		printf("testing tick: %u \n", get_ms());
		log_i("log_i test\n");
		log_e("log_e test\n");
	}
	printf("min test: %d \n",min(123,524));

	float abs_test = -12.4;
	printf("fabs test: %f \n",fabs(abs_test));

}
