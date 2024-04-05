
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int width = 0, height = 0, arr_a[260][260], arr_b[260][260];



void counter() {
    int cnt = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (arr_a[i][j] == arr_b[i][j])
                cnt++;
        }
    }
    printf("%d\n", cnt);
}

void printer() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%d ", arr_b[i][j]);
        }
        printf("\n");
    }
}

void arr_b_builder() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            arr_b[i][j] = under_max(i, j);
        }
    }
}

void scanner() {
    scanf("%d %d", &width, &height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            scanf("%d", &arr_a[i][j]);
        }
    }
}


int under_elem() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanner();
    arr_b_builder();
    counter();
    printer();
    return 0;
}