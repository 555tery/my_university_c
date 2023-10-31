cmake_minimum_required(VERSION 3.24)
project(my_university_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(StartFile.c StartFile.c Vectors.c Matrix_det_gauss.c "../C Basic/Tour_1/Ex1-1.c"
        "../C Basic/Tour_1/Ex1-2.c" "../C Basic/Tour_1/Ex1-3.c"
        "/Users/555tery/CLionProjects/my_university_c/TestFileForStudy.c"
        "../C Basic/Tour_1/Ex1-4.c"
        "../C Basic/Tour_5/Ex5_1.c" SLE_solver.c)