//
// Created by Egor Kapov on 03.12.2023.
//
#include "stdio.h"
#include "stdlib.h"

int strok_saving() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int number_zaprosov = 0;
    int request_type = -1, str_id = 0, *len_massive, now_str;
    char letter, **massive;
    scanf("%d", &number_zaprosov);
    massive = (char **) malloc(number_zaprosov * sizeof(char *)+1);
    len_massive = (int *) malloc(number_zaprosov * sizeof(int)+1);
    for (int i = 0; i < number_zaprosov; ++i) {
        scanf("%d", &request_type);
        if (request_type == 0) {
            scanf("%d", len_massive + str_id);
            massive[str_id] = (char *) malloc(len_massive[str_id] + 1);
            scanf("%s", massive[str_id]);
            str_id++;
        }
        if (request_type == 1) {
            scanf("%d", &now_str);
            free(massive[now_str]);
        }
        if (request_type == 2) {
            scanf("%d", &now_str);
            printf("%s", massive[now_str]);
            printf("\n");
        }
        if (request_type == 3) {
            scanf("%d %c", &now_str, &letter);
            int cnt = 0;
            for (int j = 0; j < len_massive[now_str]; ++j) {
                if (massive[now_str][j] == letter)
                    cnt++;
            }
            printf("%d\n", cnt);
        }
    }
    fclose(stdin);
    fclose(stdout);
    free(massive);
    free(len_massive);
}