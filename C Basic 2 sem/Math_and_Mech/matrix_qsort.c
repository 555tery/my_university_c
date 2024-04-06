//
// Created by Egor Kapov on 05.04.2024.
//
#include "stdio.h"

typedef struct matrix_plus_det {
    int matrix[65][65];
    int det;
    int size;
} matrix_plus_det;


void quicksort(matrix_plus_det *arr, int n) {
    int i = 0, j = n - 1, mid = arr[n / 2].det;
    matrix_plus_det tmp;
    while (i <= j) {
        while (arr[i].det < mid) {
            i++;
        }
        while (arr[j].det > mid) {
            j--;
        }
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (j > 0) {
        quicksort(arr, j + 1); // слева
    }
    if (i < n) {
        quicksort(&arr[i], n - i); // справа
    }
}

int determ(int a[65][65], int n) {
    int det = 0, p, h, k, i, j, temp[65][65];
    if (n == 1) {
        return a[0][0];
    } else if (n == 2) {
        det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
        return det;
    } else {
        for (p = 0; p < n; p++) {
            h = 0;
            k = 0;
            for (i = 1; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (j == p) continue;
                    temp[h][k] = a[i][j];
                    k++;
                    if (k == n - 1) {
                        h++;
                        k = 0;
                    }
                }
            }
            det += a[0][p] * (int) pow(-1, p) * determ(temp, n - 1);
        }
        return det;
    }
}


void printer(matrix_plus_det a) {
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
        arr[i].det = determ(arr[i].matrix, arr[i].size);
    }
    quicksort(arr, num_of_matrix);
    for (int i = 0; i < num_of_matrix; ++i) {
        printer(arr[i]);
    }
}