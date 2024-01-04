//
// Created by Egor Kapov on 03.01.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell_sort(int *arr, int len) {
    for (int s = len / 2; s > 0; s /= 2) {
        for (int i = s; i < len; ++i) {
            for (int j = i - s; j >= 0 and arr[j] > arr[j + s]; j -= s) {
                swap(&arr[j], &arr[j+s]);
            }
        }
    }
}

int shell_sorting() {
    int len = 0;
    scanf("%d", &len);
    int *arr;
    arr = (int *) malloc(sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        scanf("%d", &arr[i]);
    }
    shell_sort(arr, len);
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    free(arr);
}