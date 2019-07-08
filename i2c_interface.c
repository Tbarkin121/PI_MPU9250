#include "i2c_interface.h"
#include "stdio.h"
#include "pigpio.h"

int i2c_write_interface(unsigned char slave_addr, unsigned char reg_addr, 
		unsigned char length, unsigned char const *data){
	// If successful return 0
	// In not successful return 1

	printf("I2C Write Test \n");

	// int handle;
	// unsigned char command[2];
	// unsigned char value[4];

	// command[0] = 0x40;
	// command[1] = 0x20;

	// if (gpioInitialise() < 0) return 1;
	// handle = i2cOpen(1, slave_addr, 0);

	// i2cWriteDevice(handle, data, length);

	// i2cClose(handle);
	// gpioTerminate();

	return 0;
}

// int i2c_write_interface(unsigned char slave_addr, unsigned char reg_addr, 
// 		unsigned char length, unsigned char *data){
// 	// If successful return 0
// 	// In not successful return 1

// 	printf("I2C Read Test");

// 	int handle;
// 	unsigned char command[2];
// 	unsigned char value[4];

// 	command[0] = 0x40;
// 	command[1] = 0x20;

// 	if (gpioInitialise() < 0) return 1;
// 	handle = i2cOpen(1, PCF8591_I2C_ADDR, 0);

// 	value[0] = i2cReadByte(handle);
// 	printf("%3d", value[0]);

// 	i2cClose(handle);
// 	gpioTerminate();

// 	return 0;

// }

uint32_t delay_interface(uint32_t microseconds){
	if (gpioInitialise() < 0) return 1;
	return gpioDelay(microseconds);
	gpioTerminate();
}
