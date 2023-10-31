//
// Created by Egor Kapov on 31.10.2023.
//
#include <stdio.h>
#include "func.h"

int Arr_Edge() {
    int k = 0, x = 0;
    scanf("%d %d", &k, &x);
    if (x < k && x > -1)
        printf("legal");
    else printf("out of bounds");
    return 0;
}