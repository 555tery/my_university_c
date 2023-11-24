//
// Created by Egor Kapov on 24.11.2023.
//
#include "stdio.h"
#include "math.h"

int Ex1_5() {
    double A_x, A_y, B_x, B_y, C_x, C_y;
    double perimeter = 0, area = 123, AB_vector_x = 0, AB_vector_y = 0, AC_vector_x = 0, AC_vector_y = 0, BC_vector_x = 0,
            BC_vector_y = 0, AB_dlina = 0, AC_dlina = 0, BC_dlina = 0;
    scanf("%lf %lf %lf %lf %lf %lf", &A_x, &A_y, &B_x, &B_y, &C_x, &C_y);
    AB_vector_x = B_x - A_x;
    AB_vector_y = B_y - A_y;
    AC_vector_x = C_x - A_x;
    AC_vector_y = C_y - A_y;
    BC_vector_x = C_x - B_x;
    BC_vector_y = C_y - B_y;
    area = sqrt((AB_vector_x * AC_vector_y - AC_vector_x * AB_vector_y) *(AB_vector_x * AC_vector_y - AC_vector_x * AB_vector_y));
    AB_dlina = sqrt(AB_vector_x * AB_vector_x + AB_vector_y * AB_vector_y);
    AC_dlina = sqrt(AC_vector_x * AC_vector_x + AC_vector_y * AC_vector_y);
    BC_dlina = sqrt(BC_vector_x * BC_vector_x + BC_vector_y * BC_vector_y);
    perimeter = AB_dlina + AC_dlina + BC_dlina;
    printf("%0.3lf\n%.3lf", perimeter, area/2);
    return 0;
}