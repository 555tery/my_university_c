//
// Created by Egor Kapov on 05.12.2023.
//
#include "stdio.h"

void gistogram() {
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_7/input.txt", "r", stdin);
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_7/output.txt", "w", stdout);

    int arr[127] = {0};
    char symbol;
    while (scanf("%c", &symbol) != EOF) {
        arr[symbol]++;
    }
    for (int i = 32; i < 127; ++i) {
        if (arr[i] != 0) {
            printf("%c ", i);
            for (int j = 0; j < arr[i]; ++j) {
                printf("#");
            }
            printf("\n");
        }
    }
    fclose(stdout);
    fclose(stdin);
}