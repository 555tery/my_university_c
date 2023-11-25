//
// Created by Egor Kapov on 26.11.2023.
//
#include "stdio.h"

int slovo_tri_bukvi(){
    char a, b, c, d;
    a = getchar();
    b = getchar();
    c = getchar();
    d = getchar();
    if (b == 'A' && d == '.')
        printf("FITS");
    else printf("DOES NOT FIT");
    return 0;
}