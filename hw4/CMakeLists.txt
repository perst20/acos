cmake_minimum_required(VERSION 3.20)
project(hw4 C)

set(CMAKE_C_STANDARD 11)
SET(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -no-pie")
enable_language(ASM_NASM)

add_executable(hw4 main.c wisdom.h wisdom.c container.c container.h cstring_tools.c cstring_tools.h constants.h nasm_functions.asm)
