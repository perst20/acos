cmake_minimum_required(VERSION 3.21)
project(hw5)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(hw5 main.cpp)

target_link_libraries(hw5 Threads::Threads)

