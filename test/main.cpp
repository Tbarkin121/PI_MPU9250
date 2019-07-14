#include <iostream>

extern "C" {
	#include "sub.h"
}

int main(int argc, char *argv[])
{
	std::cout<<"Test c++"<<std::endl;
	test_fun();
}

