//
// Created by Egor Kapov on 27.11.2023.
//
#include "stdio.h"
#include "math.h"

#define max_size 200

int Matrix_det_gauss2() {
    int size = 0;
    float matrix[max_size][max_size];
    scanf("%d", &size);
    for (int str_num = 0; str_num < size; ++str_num) {
        for (int col_num = 0; col_num < size; ++col_num) {
            scanf("%f", &matrix[str_num][col_num]);
        }
    }
    /*for (int str_num = 0; str_num < size; ++str_num) {
        for (int col_num = 0; col_num < size; ++col_num) {
            printf("%.2lf ", matrix[str_num][col_num]);
        }
        printf("\n");
    }*/
    int sign = 1;
    float det = 1;
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] == 0) {
            //printf("%d", i);
            int help_stroka = -1;
            for (int j = i+1; j < size; ++j) {
                if (matrix[j][i] != 0){
                    help_stroka = j;
                    break;
                }
            }
        }
    }
}