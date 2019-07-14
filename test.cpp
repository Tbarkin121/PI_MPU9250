#include <iostream>

extern "C" {
    #include "inv_mpu_test.h"
}

int main(int argc, char *argv[])
{
	std::cout<<"C++ with C Test"<<std::endl;
	test2();
}
