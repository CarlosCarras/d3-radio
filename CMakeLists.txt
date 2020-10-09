cmake_minimum_required(VERSION 3.12)
project(CubeSat_Transceiver)

set(CMAKE_CXX_STANDARD 14)

add_executable(CubeSat_Transceiver main.cpp i2c.h i2c.cpp CPUT_Transceiver.cpp CPUT_Transceiver.h SendFile.cpp SendFile.h)