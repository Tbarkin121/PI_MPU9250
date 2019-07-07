#include "i2c_interface.h"
#include "stdio.h"
#include "pigpio.h"

#define PCF8591_I2C_ADDR 0x68

void i2c_write_test(void){

	printf("Testing I2C");

	int handle;
	unsigned char command[2];
	unsigned char value[4];

	command[0] = 0x40;
	command[1] = 0x20;

	if (gpioInitialise() < 0) return 1;
	handle = i2cOpen(1, PCF8591_I2C_ADDR, 0);

	i2cWriteDevice(handle, command, 2);

	value[0] = i2cReadByte(handle);
	printf("%3d", value[0]);

	i2cClose(handle);
	gpioTerminate();

}
