//
// Created by Egor Kapov on 09.01.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int maxmin() {
    int num = 0, max = -10001, max_ind = 0, min = 10001, min_ind = 0, a = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; ++i) {
        scanf("%d", &a);
        if (max < a) {
            max = a;
            max_ind = i;
        }
        if (min > a) {
            min = a;
            min_ind = i;
        }
    }
    printf("%d %d %d %d", min, min_ind, max, max_ind);
    return 0;
}