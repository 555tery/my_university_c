//
// Created by Egor Kapov on 25.11.2023.
//
#include "stdio.h"

int prosotota() {
    int N = 0;
    scanf("%d", &N);
    if (N == 1) {
        printf("NO");
        return 0;
    }
    for (int i = 2; i < N; ++i) {
        if (N % i == 0) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}