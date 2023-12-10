//
// Created by Egor Kapov on 10.12.2023.
//
#include "stdio.h"

int power_of_two(int n) {
    return 1 << n;
}

void all_inclusions() {
     int num = 0;
     long int arr[1025][13];
    scanf("%d", &num);
    for (int i = 0; i < 1025; ++i) {
        for (int j = 0; j < 13; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < num; i++) {
        int flag = 0;
        for (int j = 0; j < power_of_two(num)-1; ++j) {
            if (j % power_of_two(i) == 0) {
                flag++;
            }
            if (flag % 2 == 1) {
                arr[j][i] = 1;
            }
        }
    }
    /*for (int i = 0; i < power_of_two(num); ++i) {
        for (int j = 0; j < num; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 0; i < power_of_two(num); ++i) {
        for (int j = 0; j < num; ++j) {
            if (arr[i][j]== 1){
                printf("%d ", j+1);
            }
        }
        printf("\n");

    }
}