#include "i2c_interface.h"
#include "stdio.h"
#include "pigpio.h"

int pigpio_init(unsigned char slave_addr){
	printf("PIGPIO INIT\n");
	if (gpioInitialise() < 0) return 1;
	handle = i2cOpen(1, slave_addr, 0);
	return 0;
}
int pigpio_deinit(void){
	printf("PIGPIO DEINIT\n");
	i2cClose(handle);
	gpioTerminate();
	return 0;
}

int i2c_write_interface(unsigned char slave_addr, unsigned char reg_addr, 
		unsigned char length, unsigned char *data){
	// If successful return 0
	// In not successful return 1

//	printf("I2C Write Test \n");

	// i2cWriteDevice(handle, data, length);

	i2cWriteI2CBlockData(handle, reg_addr, data, length);

	return 0;
}

int i2c_read_interface(unsigned char slave_addr, unsigned char reg_addr, 
		unsigned char length, unsigned char *data){
	// If successful return 0
	// In not successful return 1

//	printf("I2C Read Test \n");

	// unsigned char value[4];

	i2cReadI2CBlockData(handle, reg_addr, data, length);

	return 0;
}

uint32_t delay_interface(uint32_t microseconds){
	uint32_t delay_microseconds = gpioDelay(microseconds);
	return delay_microseconds;
}

uint32_t gpioTick_interface(unsigned long *timestamp){
	uint32_t tick_microseconds = gpioTick();
//	timestamp = (unsigned long)(tick_microseconds*1000);
	return tick_microseconds;
}
