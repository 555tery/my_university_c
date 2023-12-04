//
// Created by Egor Kapov on 04.12.2023.
//
#include "stdio.h"

int number_experiment() {
    int request_num = 0;
    scanf("%d", &request_num);
    int number = 0, res = 1;
    for (int i = 0; i < request_num; ++i) {
        res = 1, number =1;
        scanf("%d", &number);
        while (number % 2 == 0) {
            number /= 2;
            res = res*2;
        }
        printf("%d", res);
        printf("\n");
    }

}