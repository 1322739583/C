cmake_minimum_required(VERSION 3.17)
project(C)

set(CMAKE_CXX_STANDARD 14)




add_executable(time basic/time/time.c)
add_executable(signal basic/signal/signal.c)