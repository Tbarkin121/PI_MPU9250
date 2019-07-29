#include <stdint.h>

#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_
	int handle;

	int i2c_write_interface(unsigned char slave_addr, unsigned char reg_addr, 
		unsigned char length, unsigned char *data);

	int i2c_read_interface(unsigned char slave_addr, unsigned char reg_addr, 
		unsigned char length, unsigned char *data);
	
	uint32_t delay_interface(uint32_t microseconds);
	uint32_t gpioTick_interface(unsigned long *timestamp);

	int pigpio_init(unsigned char slave_addr);
	int pigpio_deinit(void);


#endif  /* #ifndef _I2C_INTERFACE_H_ */
