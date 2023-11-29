//
// Created by Egor Kapov on 29.11.2023.
//
#include "stdio.h"

int difference() {
    char arr1[28], arr2[28];
    for (int i = 0; i < 28; ++i) {
        arr1[i] = 0;
        arr2[i] = 0;
    }
    int flag = 0;
    scanf("%s", arr1);
    scanf("%s", arr2);
    for (int i = 0; i < 28; ++i) {
        for (int j = 0; j < 28; ++j) {
            if (arr2[j] == arr1[i]) {
                arr1[i] = '0';

            }
        }
    }
    char baza = 'A';
    for (int i = 0; i < 28; ++i) {
        for (int j = 0; j <28; ++j) {
            if (arr1[j] == baza) {
                printf("%c", arr1[j]);
                flag++;
            }

        }

        baza += 1;
    }

    if (flag == 0)
        printf("Empty Set");
}
