cmake_minimum_required(VERSION 3.24)
project(my_university_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(my_university_c
        Algebra_det_search.c)
