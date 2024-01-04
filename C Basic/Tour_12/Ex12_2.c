//
// Created by Egor Kapov on 02.01.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min_ind = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min_ind])
                min_ind = j;
        }
        if (min_ind != i){
            swap(&arr[i], &arr[min_ind]);
        }
    }
}

int sel_sort() {
    int len = 0;
    scanf("%d", &len);
    int *arr;
    arr = (int *) malloc(sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, len);
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }

}