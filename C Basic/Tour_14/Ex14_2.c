//
// Created by Egor Kapov on 10.12.2023.
//

#include "stdio.h"
#include "iso646.h"
#include "stdlib.h"

int test(char **board, int col_num, int i0, int j0) {
    int i = i0, j = j0;
    i--;
    j--;
    while ((i >= 0) and (j >= 0)) {
        if (board[i][j] == 'X') {
            return 0;
        }
        i--;
        j--;
    }
    i = i0;
    j = j0;
    i--;
    while ((i >= 0) and (j >= 0)) {
        if (board[i][j] == 'X') {
            return 0;
        }
        i--;
    }
    i = i0;
    j = j0;
    i--;
    j++;
    while ((i >= 0) and (j < col_num)) {
        if (board[i][j] == 'X') {
            return 0;
        }
        i--;
        j++;
    }
    return 1;
}

int round(char **board, int str_num, int col_num, int i) {
    int j = 0;
    while ((j < col_num)) {
        if (board[i][j] == '?') {
            if (test(board, col_num, i, j)) {
                board[i][j] = 'X';
                if (i == str_num - 1) {
                    return 1;
                } else {
                    if (round(board, str_num, col_num, i + 1)) {
                        return 1;
                    }
                }
                board[i][j] = '?';
            }
        }
        j++;
    }
    return 0;
}

int chess() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); // открываются файлы
    int str_num, col_num, q = 0;
    char **board; // массив основного поля
    scanf("%d %d", &str_num, &col_num);// сканим размеры поля
    board = (char **) malloc(str_num * sizeof(char *)); // выделяем память под кол-во строк
    for (int i = 0; i < str_num; i++) {
        board[i] = (char *) malloc((col_num + 1) * sizeof(char)); //выделяем память под кол-во столбцов
        scanf("%s", board[i]);
    }
    // входные: массив строк, кол-во строк, кол-во столбцов, строка начала перебора
    q = round(board, str_num, col_num, 0); //рекурсивным перебором присваиваем тру или фолз
    if (q) {
        printf("YES\n");
        for (int i = 0; i < str_num; i++) {
            for (int j = 0; j < col_num; j++) {
                if (board[i][j] != '?') {
                    printf("%c", board[i][j]);
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    } else {
        printf("NO");
    }

    return 0;
}