//
// Created by Egor Kapov on 09.01.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int ab(int N) {
    if (N == 1) {
        //printf("NO");
        return 0;
    }
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            //printf("NO");
            return 0;
        }
    }
    // printf("YES");
    return 1;
}

int prosota2() {
    int a = 0, cnt = 0;
    scanf("%d", &a);
    for (int i = 2; i  <= a; ++i) {
        if (ab(i)) {
            printf("%d ", i);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}