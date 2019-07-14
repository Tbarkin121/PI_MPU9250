#include <iostream>

extern "C" {
    #include "stdio.h"
    #include "inv_mpu_test.h"
    void test2();
}

int main(int argc, char *argv[])
{
	std::cout<<"Test"<<std::endl;
	test2();
}
