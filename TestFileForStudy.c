//
// Created by Egor Kapov on 31.10.2023.
//
#define m 123

#include "stdio.h"

int TestFileForStudy() {
    char a[m];
    gets(a);
    int i = 0;
    while (a[i] != '\0') {
        if (a[i] == ' ')
            printf("%c\n", a[i]);
        i++;
    }
    return 0;
}