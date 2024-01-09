//
// Created by Egor Kapov on 09.01.2024.
//
#include "stdio.h"
#include "stdlib.h"

int main() {
    int len;
    scanf("%d", &len);
    if (len == 0) {
        printf("0");
        return 0;
    } else if (len == 1) {
        printf("2");
        return 0;
    } else if (len == 2) {
        printf("3");
        return 0;
    }
    int *arr;
    arr = (int *) malloc((len + 1) * sizeof(int));
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 3;
    for (int i = 3; i <= len; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%d", arr[len]);
    free(arr);
    return 0;
}