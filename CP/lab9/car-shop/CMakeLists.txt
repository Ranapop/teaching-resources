cmake_minimum_required(VERSION 3.15)
project(car_shop C)

set(CMAKE_C_STANDARD 99)

add_executable(car_shop main.c buyer.h buyer.c)