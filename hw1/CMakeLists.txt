cmake_minimum_required(VERSION 3.20)
project(hw1 C)

set(CMAKE_C_STANDARD 11)

add_executable(hw1 main.c wisdom.h wisdom.c container.c container.h cstring_tools.c cstring_tools.h constants.h)
