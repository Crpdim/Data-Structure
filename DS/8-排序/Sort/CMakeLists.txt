cmake_minimum_required(VERSION 3.21)
project(Sort C)

set(CMAKE_C_STANDARD 99)

add_executable(Sort main.c Sort.h Heap.h)
