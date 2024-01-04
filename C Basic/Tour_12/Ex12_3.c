//
// Created by Egor Kapov on 03.01.2024.
//
#include "stdlib.h"
#include "stdio.h"
#include "iso646.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert_sort(int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j -1;
        }arr[j+1] = key;
    }
}

int ins_sort() {
    int len = 0;
    scanf("%d", &len);
    int *arr;
    arr = (int *) malloc(sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        scanf("%d", &arr[i]);
    }
    insert_sort(arr, len);
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    free(arr);
}