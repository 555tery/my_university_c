cmake_minimum_required(VERSION 3.24)
project(my_university_c C)

set(CMAKE_Cpp_STANDARD 11)

include_directories(.)

add_executable(StartFile.c StartFile.c
        "../C Basic/Tour_5/Ex5_1.c"  "../C Basic 2 sem/Tour_1/Ex1_2.c"
        ../TestFileForStudy.c
        "../C Basic 2 sem/Math_and_Mech/vector_mergesort.c"
)