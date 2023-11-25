//
// Created by Egor Kapov on 25.11.2023.
//
#include "stdio.h"

int sum_1_to_N() {
    int res = 0, N = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        res += i;
    }
    printf("%d", res);
    return 0;
}