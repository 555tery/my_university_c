cmake_minimum_required(VERSION 3.24)
project(my_university_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(StartFile.c StartFile.c Vectors.c Matrix_det_gauss.c)