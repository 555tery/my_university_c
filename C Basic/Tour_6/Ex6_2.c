//
// Created by Egor Kapov on 03.12.2023.
//
#include "stdio.h"

int japanese_problem(){
    int start[100][100];
    int res[100][100];
    int cnt = 0, now= 0;
    int num_strok = 0, num_column = 0;
    scanf("%d %d", &num_strok, &num_column);
    for (int i = 0; i < num_strok; ++i) {
        for (int j = 0; j <num_column ; ++j) {
            scanf("%d", &start[i][j]);
        }
    }
    for (int i = 0; i < num_strok; ++i) {
        now = start[i][0];
        for (int j = 1; j < num_column+1; ++j) {
            if (start[i][j] == 1)
                now++;
            if (start[i][j] == 0 && now != 0){
                printf("%d ", now);
                now = 0;
            }
        }
        printf("\n");
    }
    for (int i = 0; i < num_column+1; ++i) {
        now = start[0][i];
        for (int j = 1; j < num_strok+1; ++j) {
            if (start[j][i] == 1)
                now++;
            if (start[j][i] == 0 && now != 0){
                printf("%d ", now);
                now = 0;
            }
        }
        if (i != num_column)
            printf("\n");
    }
}