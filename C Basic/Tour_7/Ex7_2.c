//
// Created by Egor Kapov on 05.12.2023.
//
#include "stdio.h"

void words_number() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int mas[100] = {0};
    unsigned char symbol[500];
    int cnt;
    while (scanf("%s", symbol) != EOF) {
        cnt = 0;
        for (int i = 0; symbol[i] != '\0'; ++i) {
            cnt++;
        }
        mas[cnt]++;
    }
    for (int i = 0; i < 100; ++i) {
        if (mas[i] != 0) {
            printf("%d - %d\n", i, mas[i]);
        }
    }
    fclose(stdout);
    fclose(stdin);
}