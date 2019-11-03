cmake_minimum_required(VERSION 3.15)
project(dummy_repo C)

set(CMAKE_C_STANDARD 99)

add_executable(dummy_repo main.c buyer.h buyer.c)
