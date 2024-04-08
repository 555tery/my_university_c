

#include "stdio.h"
#include "stdlib.h"

int num_of_matrix = 0;

int neg_one_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) { return a; }
    int tmp = a;
    for (int i = 1; i < b; ++i) {
        tmp *= a;
    }
    return tmp;
}

typedef struct matrix_plus_det {
    int **matrix;
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

int determinant(int **matrix, int n) {
    int **submatrix;
    submatrix = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        submatrix[i] = (int *) malloc(n * sizeof(int));
    }
    int det = 0;
    if (n == 1) {
        det = matrix[0][0];
        for (int i = 0; i < n; ++i) {
            free(submatrix[i]);
        }
        free(submatrix);
        return det;
    } else if (n == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        for (int i = 0; i < n; ++i) {
            free(submatrix[i]);
        }
        free(submatrix);
        return det;
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
            det += neg_one_pow(-1, k) * matrix[0][k] * determinant(submatrix, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            free(submatrix[i]);
        }
        free(submatrix);
        return det;
    }
}

void matrix_builder(matrix_plus_det arr[]) {
    arr->matrix = (int **) malloc(arr->size * sizeof(int *));
    for (int i = 0; i < arr->size; ++i) {
        arr->matrix[i] = (int *) malloc(arr->size * sizeof(int));
    }
}


void matrix_debuilder(matrix_plus_det arr[]) {
    for (int j = 0; j < num_of_matrix; ++j) {
        for (int i = 0; i < arr->size; ++i) {
            free(arr[j].matrix[i]);
        }
        free(arr[j].matrix);
    }
    free(arr);
}

void printer(matrix_plus_det a) {
    for (int i = 0; i < a.size; ++i) {
        for (int j = 0; j < a.size; ++j) {
            printf("%d ", a.matrix[i][j]);
        }
        printf("\n");
    }
}

int matrix_qsort() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &num_of_matrix);
    matrix_plus_det *arr = (matrix_plus_det *) malloc(num_of_matrix * sizeof(matrix_plus_det));
    for (int i = 0; i < num_of_matrix; ++i) {
        scanf("%d", &arr[i].size);
        matrix_builder(&arr[i]);
        for (int j = 0; j < arr[i].size; ++j) {
            for (int k = 0; k < arr[i].size; ++k) {
                scanf("%d", &arr[i].matrix[j][k]);
            }
        }
        arr[i].det = determinant(arr[i].matrix, arr[i].size);
    }
    quicksort(arr, num_of_matrix);
    for (int i = 0; i < num_of_matrix; ++i) {
        printer(arr[i]);
    }
    matrix_debuilder(arr);
    return 0;
}