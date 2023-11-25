//
// Created by Egor Kapov on 26.11.2023.
//
#include "stdio.h"
#include "string.h"

int day_of_week() {
    char a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();
    if (a == 'M' && b == 'o' && c == 'n')
        printf("1");
    if (a == 'T' && b == 'u' && c == 'e')
        printf("2");
    if (a == 'W' && b == 'e' && c == 'd')
        printf("3");
    if (a == 'T' && b == 'h' && c == 'u')
        printf("4");
    if (a == 'F' && b == 'r' && c == 'i')
        printf("5");
    if (a == 'S' && b == 'a' && c == 't')
        printf("6");
    if (a == 'S' && b == 'u' && c == 'n')
        printf("7");
    return 0;
}