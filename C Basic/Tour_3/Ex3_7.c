//
// Created by Egor Kapov on 13.03.2024.
//
#include "stdio.h"
#include "iso646.h"

int summa123() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int sum = 0, buffer = 0;
    char a;
    while (scanf("%c", &a)) {

        if (a - '0' < 10 and a - '0' > -1) {
            buffer *= 10;
            buffer += a - '0';
        }
        else {
            sum += buffer;
            buffer = 0;
        }
        if (a == '.')
            break;
    }
    printf("%d", sum);
}