//
// Created by Egor Kapov on 30.10.2023.
//
#include "func.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "iso646.h"

typedef struct vector {
    int vector[65];
    int norm;
    int size;
} vector;

int norm_cnt() {

}

void mergeSort(vector *a, int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    int i = l;
    int j = mid + 1;
    vector *tmp = (vector *) malloc(r * sizeof(vector));
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
}

void printer(vector a) {
    for (int i = 0; i < a.size; ++i) {
            printf("%d ", a.vector[i]);
    }
}
int main() {
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
    mergeSort(arr, num_of_vectors);
    for (int i = 0; i < num_of_vectors; ++i) {
        printer(arr[i]);
    }
}
