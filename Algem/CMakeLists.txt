cmake_minimum_required(VERSION 3.24)
project(my_university_c C)

set(CMAKE_Cpp_STANDARD 11)

include_directories(.)

add_executable(StartFile.c StartFile.c
        "../C Basic/Tour_5/Ex5_1.c"  "../C Basic 2 sem/Tour_1/Ex1_2.c"
        "../C Basic 2 sem/Tour_2/Ex2_1.c"
        "../C Basic/Tour_3/Ex3_7.c"


        "../C Basic/Tour_2/Ex2_4.c"
        "../C Basic/Tour_2/Ex2_4.c"
        "../C Basic 2 sem/Math_and_Mech/arctg_taylor.c"
        "../C Basic/Tour_8/Ex8_2.c"
        ../TestFileForStudy.c
        "../C Basic 2 sem/Math_and_Mech/matrix_qsort.c"
)