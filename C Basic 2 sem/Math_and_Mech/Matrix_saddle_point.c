//
// Created by Egor Kapov on 15.03.2024.
//

#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int **arr;
int width = 0, height = 0;

void **matrix_init() {
    arr = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; ++i) {
        arr[i] = (int *) calloc(width, sizeof(int));
    }
}

void matrix_elements() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
}


void clean() {
    for (int i = 0; i < height; ++i) {
        free(arr[i]);
    }
    free(arr);
}

int min_in_line(int num, int *matrix) {
    for (int i = 0; i < width; ++i) {
        if (matrix[i] < num)
            return 0;
    }
    return 1;
}

int max_in_col(int num, int stolbec) {
    for (int i = 0; i < height; ++i) {
        if (arr[i][stolbec] > num)
            return 0;
    }
    return 1;
}

int test(int i, int j) {
    if (min_in_line(arr[i][j], arr[i]) and max_in_col(arr[i][j], j))
        return 1;
    else return 0;
}

int average_col(int col) {
    int x = 0;
    int average;
    for (int i = 0; i < height; ++i) {
        x += arr[i][col];
    }
    average = x / height;
    return average;
}

void matrix_print() {
    int average;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (test(i, j)) {
                average = average_col(j);
                printf("%d ", average);
            } else printf("%d ", arr[i][j]);
        }
        printf("%c", '\n');
    }
}

int Matrix_saddle_point() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int points_counter = 0, points_sum = 0;
    scanf("%d %d", &width, &height);
    matrix_init();
    matrix_elements();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (test(i, j)) {
                points_sum += arr[i][j];
                points_counter++;
            }
        }
    }
    printf("%d\n", points_counter);
    matrix_print();
    clean();
}