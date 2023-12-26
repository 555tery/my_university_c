//
// Created by Egor Kapov on 26.12.2023.
//
#include <stdio.h>
#include <stdlib.h>

void quicksort_pls(int *arr, int n) { // справа оставим элементы больше mid, слева -- меньше
    int i = 0, j = n - 1, mid = arr[n / 2], tmp;
    while (i <= j) {
        while (arr[i] < mid) {
            i++;
        }
        while (arr[j] > mid) {
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
        quicksort_pls(arr, j + 1); // слева
    }
    if (i < n) {
        quicksort_pls(&arr[i], n - i); // справа
    }
}


int quicksort_bin() {
    FILE *in = fopen("input.bin", "rb");
    FILE *out = fopen("output.bin", "wb");
    int n;
    fread(&n, sizeof(int), 1, in);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        fread(&arr[i], sizeof(int), 1, in);
    }
    quicksort_pls(arr, n);
    fwrite(arr, sizeof(int), n, out);
    return 0;
}