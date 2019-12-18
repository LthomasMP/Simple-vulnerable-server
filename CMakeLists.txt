cmake_minimum_required(VERSION 3.7.0)
project(vulnerable_simple_server)

set(CMAKE_C_STANDARD 11)
set(GCC_COMPILE_FLAGS "-fno-stack-protector -no-pie")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COMPILE_FLAGS}")

add_executable(Server server.c)