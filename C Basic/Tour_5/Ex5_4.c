//
// Created by Egor Kapov on 30.11.2023.
//
#include "stdio.h"

int words() {
    char start[30], slovo[30];


    scanf("%s", start);
    while (scanf("%s", slovo) != EOF) {
        int flag = 0;
        for (int i = 0; slovo[i] != '\0'; ++i) {
            for (int j = 0; start[j] != '\0'; ++j) {
                if (slovo[i] == start[j])
                    flag++;
            }
        }
        if (flag == 0)
            printf("%s\n", slovo);
    }
}