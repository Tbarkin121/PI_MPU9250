#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_

	int i2c_write_interface(unsigned char slave_addr, unsigned char reg_addr, 
		unsigned char length, unsigned char const *data);

	// int i2c_read_interface(unsigned char slave_addr, unsigned char reg_addr, 
	// 	unsigned char length, unsigned char *data);

#endif  /* #ifndef _I2C_INTERFACE_H_ */