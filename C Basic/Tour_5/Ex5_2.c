//
// Created by Egor Kapov on 28.11.2023.
//
#include "stdio.h"

int colors() {
    int res[2];
    int res_count = 0;
    char arr[27];
    char color[7];
    for (int i = 0; i < 7; ++i) {
        color[i] = 0;
    }
    scanf("%s", color);
    for (int i = 0; i < 27; ++i) {
        arr[i] = 0;
    }
    scanf("%s", arr);
    if (color[0] == 'p') {
        for (int i = 0; i < 27; ++i) {
            if (res_count >= 2) {
                for (int j = 0; j < 2; ++j) {
                    printf("%d ", res[j]+1);
                }
                return 0;
            }
            if (arr[i] == 'R' || arr[i] == 'B') {
                res[res_count] = i;
                res_count++;
            }

        }
    }
    if (color[0] == 'g') {
        for (int i = 0; i < 27; ++i) {
            if (res_count >= 2) {
                for (int j = 0; j < 2; ++j) {
                    printf("%d ", res[j]+1);
                }
                return 0;
            }
            if (arr[i] == 'Y' || arr[i] == 'B') {
                res[res_count] = i;
                res_count++;
            }

        }

    }
    if (color[0] == 'o') {
        for (int i = 0; i < 27; ++i) {
            if (res_count >= 2) {
                for (int j = 0; j < 2; ++j) {
                    printf("%d ", res[j]+1);
                }
                return 0;
            }
            if (arr[i] == 'R' || arr[i] == 'Y') {
                res[res_count] = i;
                res_count++;
            }

        }
    }
}

