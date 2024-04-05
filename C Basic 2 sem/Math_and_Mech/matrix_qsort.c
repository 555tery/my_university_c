//
// Created by Egor Kapov on 05.04.2024.
//
#include "stdlib.h"
#include "stdio.h"
#include "iso646.h"
#include "string.h"
#include "math.h"

typedef struct matrix_plus_det {
    int matrix[65][65];
    int det;
    int size;
} matrix_plus_det;

int cmp(matrix_plus_det *a, matrix_plus_det *b) {
    if (a->det > b->det)
        return 1;
    else if (a->det < b->det)
        return -1;
    else return 0;
}


void quicksort(matrix_plus_det *arr, int n){
    int i = 0, j = n - 1, mid = arr[n/2].det;
    matrix_plus_det tmp;
    while (i <= j){
        while(arr[i].det < mid){
            i++;
        }
        while (arr[j].det > mid){
            j--;
        }
        if (i <= j){
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (j > 0){
        quicksort(arr, j + 1); // слева
    }
    if (i < n){
        quicksort(&arr[i], n - i); // справа
    }
}

int determinant(int matrix[65][65], int n) {
    int submatrix[65][65], det = 0;
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        for (int k = 0; k < n; k++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k) continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += pow(-1, k) * matrix[0][k] * determinant(submatrix, n - 1);
        }
        return det;
    }
}
void printer(matrix_plus_det a){
    for (int i = 0; i < a.size; ++i) {
        for (int j = 0; j < a.size; ++j) {
            printf("%d ", a.matrix[i][j]);
        }
        printf("\n");
    }
}
void matrix_qsort() {
    int num_of_matrix = 0;
    scanf("%d", &num_of_matrix);
    matrix_plus_det arr[100];
    for (int i = 0; i < num_of_matrix; ++i) {
        scanf("%d", &arr[i].size);
        for (int j = 0; j < arr[i].size; ++j) {
            for (int k = 0; k < arr[i].size; ++k) {
                scanf("%d", &arr[i].matrix[j][k]);
            }
        }
        arr[i].det=determinant(arr[i].matrix, arr[i].size);
    }
    quicksort(arr, num_of_matrix);
    for (int i = 0; i < num_of_matrix; ++i) {
        printer(arr[i]);
    }
}