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
#include "mltypes.h"
#include "i2c_interface.h"
/* Private typedef -----------------------------------------------------------*/
/* Data read from MPL. */
#define PRINT_ACCEL     (0x01)
#define PRINT_GYRO      (0x02)
#define PRINT_QUAT      (0x04)
#define PRINT_COMPASS   (0x08)
#define PRINT_EULER     (0x10)
#define PRINT_ROT_MAT   (0x20)
#define PRINT_HEADING   (0x40)
#define PRINT_PEDO      (0x80)
#define PRINT_LINEAR_ACCEL (0x100)
#define PRINT_GRAVITY_VECTOR (0x200)

volatile uint32_t hal_timestamp = 0;
#define ACCEL_ON        (0x01)
#define GYRO_ON         (0x02)
#define COMPASS_ON      (0x04)

#define MOTION          (0)
#define NO_MOTION       (1)

/* Starting sampling rate. */
#define DEFAULT_MPU_HZ  (100)

#define FLASH_SIZE      (512)
#define FLASH_MEM_START ((void*)0x1800)

#define PEDO_READ_MS    (1000)
#define TEMP_READ_MS    (500)
#define COMPASS_READ_MS (100)

void test_fun(void) {
    printf("test 1 \n");
}
// void test2(void) {
//     printf("test 2 \n");
// }

int main(void)
{
	test_fun();
    pigpio_init(0x68);
//	printf("result of pigpio_init : %d \n",pigpio_init(0x68));

	inv_error_t result;
    unsigned char accel_fsr,  new_temp = 0;
    unsigned short gyro_rate, gyro_fsr;
    unsigned char new_compass = 0;
    unsigned short compass_fsr;
    unsigned long timestamp;
    struct int_param_s int_param;

//	result = mpu_init(&int_param);
// 	if (result) {
//    	printf("Could not initialize gyro.\n");
//	}
	mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);
	mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
    mpu_set_sample_rate(DEFAULT_MPU_HZ);
    mpu_set_compass_sample_rate(1000 / COMPASS_READ_MS);

    mpu_get_sample_rate(&gyro_rate);
    mpu_get_gyro_fsr(&gyro_fsr);
    mpu_get_accel_fsr(&accel_fsr);
    mpu_get_compass_fsr(&compass_fsr);
    printf("Sample Rate %d\n",gyro_rate);
    printf("Gyro range %d\n",gyro_fsr);
    printf("Accel range %d\n",accel_fsr);
    printf("Compass range %d\n",compass_fsr);

    short accel_data[3];
    short gyro_data[3];
    short compass_data[3];
    for(int i = 0; i<1000; i++){
        mpu_get_accel_reg(accel_data, &timestamp);
	mpu_get_gyro_reg(gyro_data, &timestamp);
	mpu_get_compass_reg(compass_data, &timestamp);
        printf("Accel:   %d, %d, %d \n",accel_data[0],accel_data[1],accel_data[2]);
        printf("Gyro:    %d, %d, %d \n",gyro_data[0],gyro_data[1],gyro_data[2]);
        printf("Compass: %d, %d, %d \n",compass_data[0],compass_data[1],compass_data[2]);
//        printf("Accel Data? %d, %d, %d \n",accel_data[0],accel_data[1],accel_data[2]);
        delay_interface(100000);
    }
    for(int i = 0; i<10; i++){
        printf("Test %d\n",i);
        //delay_interface(1);
    }
   pigpio_deinit();
}
