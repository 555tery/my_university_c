

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "iso646.h"

typedef struct vector {
    int vector[65];
    int norm;
    int size;
} vector;

int norm_cnt(int* arr, int len) {
    int res =0;
    for (int i = 0; i < len; ++i) {
        res += pow(arr[i], 2);
    }
    return (int) sqrt(res);
}

void mergeSort(vector *a, int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    int i = l;
    int j = mid + 1;
    vector tmp[66];
    for (int step = 0; step < r - l + 1; step++) {
        if ((j > r) or ((i <= mid) and (a[i].norm < a[j].norm))) {
            tmp[step] = a[i];
            i++;
        } else {
            tmp[step] = a[j];
            j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++)
        a[l + step] = tmp[step];
    free(tmp);
}

void printer(vector a) {
    for (int i = 0; i < a.size; ++i) {
        printf("%d ", a.vector[i]);
    }
    printf("\n");
}

int vector_mergesort() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int num_of_vectors = 0;
    scanf("%d", &num_of_vectors);
    vector arr[100];
    for (int i = 0; i < num_of_vectors; ++i) {
        scanf("%d", &arr[i].size);
        for (int j = 0; j < arr[i].size; ++j) {
            scanf("%d", &arr[i].vector[j]);
        }
        arr[i].norm = norm_cnt(arr[i].vector, arr[i].size);
    }
    mergeSort(arr, 0, num_of_vectors-1);
    for (int i = 0; i < num_of_vectors; ++i) {
        printer(arr[i]);
    }
    return 0;
}
