#include "i2c_interface.h"
#include "stdio.h"
#include "pigpio.h"

int pigpio_init(unsigned char slave_addr){
	if (gpioInitialise() < 0) return 1;
	handle = i2cOpen(1, slave_addr, 0);
	return 0;
}
int pigpio_deinit(void){
	i2cClose(handle);
	gpioTerminate();
}

int i2c_write_interface(unsigned char slave_addr, unsigned char reg_addr, 
		unsigned char length, unsigned char *data){
	// If successful return 0
	// In not successful return 1

//	printf("I2C Write Test \n");

	// i2cWriteDevice(handle, data, length);
	int h;
	if (gpioInitialise() < 0) return 1;
	h = i2cOpen(1, slave_addr, 0);

	i2cWriteI2CBlockData(h, reg_addr, data, length);

	i2cClose(h);
	gpioTerminate();

	return 0;
}

int i2c_read_interface(unsigned char slave_addr, unsigned char reg_addr, 
		unsigned char length, unsigned char *data){
	// If successful return 0
	// In not successful return 1

//	printf("I2C Read Test \n");

	// unsigned char value[4];
	int h;
        if (gpioInitialise() < 0) return 1;
        h = i2cOpen(1, slave_addr, 0);

	i2cReadI2CBlockData(h, reg_addr, data, length);

	i2cClose(h);
        gpioTerminate();

	return 0;
}

uint32_t delay_interface(uint32_t microseconds){
	if (gpioInitialise() < 0) return 1;
	uint32_t delay_microseconds = gpioDelay(microseconds);
	gpioTerminate();
	return delay_microseconds;
}

uint32_t gpioTick_interface(unsigned long *timestamp){
	if (gpioInitialise() < 0) return 1;
	uint32_t tick_microseconds = gpioTick();
	gpioTerminate();
//	timestamp = (unsigned long)(tick_microseconds*1000);
	return tick_microseconds;
}
