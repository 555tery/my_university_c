//
// Created by Egor Kapov on 04.12.2023.
//

#include "stdio.h"


int symbol_number(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int mas[256] = {0};
    unsigned char symbol;
    while (scanf("%c", &symbol) != EOF) {
        mas[symbol]++;
    }
    for (int i = 13; i < 256; ++i) {
        if (mas[i] != 0) {
            printf("%d : %c - %d\n", i, i, mas[i]);
        }
    }
    fclose(stdout);
    fclose(stdin);
}