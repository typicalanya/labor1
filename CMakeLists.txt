cmake_minimum_required(VERSION 3.17)
project(medical)

set(CMAKE_CXX_STANDARD 14)

add_executable(medical main.cpp src/medical.h src/medical.cpp src/utils.h src/utils.cpp src/staff.h src/staff.cpp)