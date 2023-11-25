//
// Created by Egor Kapov on 25.11.2023.
//
#include "stdio.h"

int sum_of_even() {
    int N = 0, res = 0, element = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &element);
        if (element % 2 == 0)
            res += element;
    }
    printf("%d", res);
}