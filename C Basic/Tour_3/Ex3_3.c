//
// Created by Egor Kapov on 26.11.2023.
//
#include "stdio.h"

int I_am_better() {
    char a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();
    while (c != '.' && b != '.' && a != '.') {
        printf("%c", a);
        a = b;
        b = c;
        c = getchar();
    }
    if (b == 'r' && a == 'e') {
        printf("est");
        return 0;
    }

    if (b != 'e') {
        printf("%c", a);
        printf("%c", b);
        printf("er");
        return 0;
    }
    if (b == 'e') {
        printf("%c", a);
        printf("%c", b);
        printf("r");
        return 0;
    }
}
