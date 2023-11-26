//
// Created by Egor Kapov on 26.11.2023.
//
#include "stdio.h"

int Divide_by_15() {
    char a, b;
    int sum = 0;
    a = getchar();
    a = a-'0';
    b = getchar();
    sum += a;
    while (b != '.') {
        a = b;
        a = a-'0';
        sum += a;
        b = getchar();


    }
    if (sum % 3 == 0 && a % 5 == 0)
        printf("YES");
    else printf("NO");
}