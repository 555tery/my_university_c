cmake_minimum_required(VERSION 3.24)
project(my_university_c C)

set(CMAKE_Cpp_STANDARD 11)

include_directories(.)

add_executable(StartFile.c StartFile.c
        "/Users/555tery/CLionProjects/my_university_c/TestFileForStudy.c"
        "../C Basic/Tour_5/Ex5_1.c"  "../C Basic 2 sem/Tour_1/Ex1_2.c"
        "../C Basic 2 sem/Tour_2/Ex2_1.c"
        "../C Basic/Tour_3/Ex3_7.c"
        "../C Basic 2 sem/Math_and_Mech/Matrix_saddle_point.c"
        "../C Basic 2 sem/Math_and_Mech/Prost_matrix.c"
)