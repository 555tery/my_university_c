//
// Created by Egor Kapov on 31.10.2023.
//
#include "stdio.h"

int Ex1_4() {
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    if (a == 0) {
        printf("%d ", 0);
        printf("%d ", 0);
        printf("%d ", 0);
        printf("%d ", 0);
        return 0;
    }
    //начало первого пункта (округление вниз)
    if (a < 0 && a % b != 0) {
        printf("%d ", a / b - 1);
    }
    if (a < 0 && a % b == 0) {
        printf("%d ", a / b);
    }
    if (a > 0) {
        printf("%d ", a / b);
    }
    //начало второго пункта (округление вверх)
    if (a < 0) {
        printf("%d ", a / b);
    }
    if (a > 0 && a % b != 0) {
        printf("%d ", a / b + 1);
    }
    if (a > 0 && a % b == 0) {
        printf("%d ", a / b);
    }
    //начало третьего пункта (округленное в сторону нуля)
    if (a < 0) {
        printf("%d ", a / b);
    }
    if (a > 0) {
        printf("%d ", a / b);
    }
    //начало чевертого пункта (остаток Р от деления а на б лежащий в диапазоне от нуля до б)
    if (a % b == 0) {
        printf("%d", 0);
        return 0;
    }

    if (a > 0) {
        printf("%d ", a % b);
    }
    if (a < 0 && a % b != 0) {
        printf("%d ", b + a % b);
    }
}