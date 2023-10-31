//
// Created by Egor Kapov on 31.10.2023.
//
#include "stdio.h"
int Min_of_three(){
    int a = 0, min = 101;
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &a);
        if (a<min)
            min = a;
    }
    printf("%d", min);
    return 0;
}
