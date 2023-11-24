cmake_minimum_required(VERSION 3.24)
project(my_university_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(StartFile.c StartFile.c
        "/Users/555tery/CLionProjects/my_university_c/TestFileForStudy.c"
        "../C Basic/Tour_5/Ex5_1.c" "../C Basic/Tour_9/Ex9_1.c" "../C Basic/Tour_9/Ex9_6.c" "../C Basic/Tour_9/Ex9_2.c" "../C Basic/Tour_11/Ex11_1.c" "../C Basic/Tour_10/Ex10_1.c" "../C Basic/Tour_10/Ex10_2.c" "../C Basic/Tour_1/Ex1-4.c" "../C Basic/Tour_1/Ex1_5.c")