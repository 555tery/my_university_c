//
// Created by Egor Kapov on 09.01.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int signs() {
    double num = 0, a = 0, zero = 0, minus = 0, plus = 0;
    scanf("%lf", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%lf", &a);
        if (a < 0)
            minus++;
        else if (a > 0)
            plus++;
        else if (a == 0)
            zero++;
    }
    printf("%0.5lf %0.5lf %0.5lf", minus/num, zero/num, plus/num);
}