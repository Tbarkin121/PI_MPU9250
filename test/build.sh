#!/bin/bash

# g++ main.cpp -o main
#./testpp



#gcc -c -oinv_mpu_test.o inv_mpu_test.c i2c_interface -lpigpio -lpthread
g++ -c -o main.o main.cpp
gcc -c -o sub.o sub.c
g++ -o myprogram main.o sub.o
# link them together, using the C++ library libmycpplib:
#g++ -oprogram otest.o oinv_mpu_test.o -lmycpplib