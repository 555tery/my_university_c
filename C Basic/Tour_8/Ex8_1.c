//
// Created by Egor Kapov on 05.12.2023.
//
#include "stdio.h"

void one_cnt(){
    int max = 1;
    int num = 0, cnt = 1;
    scanf("%d", &num);
    int flag = 1;
    while (flag){
        if (num%2 == 1){
            cnt++;
        }
        if (num%2 == 0){
            if (cnt > max)
                max = cnt;
            cnt = 1;
        }
        num >>=1;
        if (num == 0)
            flag--;


    }
    printf("%d", max);
}