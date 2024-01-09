//
// Created by Egor Kapov on 27.12.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tokens_s {
    int num;
    char **arr;
} Tokens;

int checker_not(const char *str, const char *delims, int a) {
    for (int i = 0; delims[i] != '\0'; ++i) {
        if (delims[i] == str[a])
            return 0;
    }
    return 1;
}

int checker_yes(const char *str, const char *delims, int a) {
    for (int i = 0; delims[i] != '\0'; ++i) {
        if (delims[i] == str[a])
            return 1;
    }
    return 0;
}

void tokensSplit(Tokens *tokens, const char *str, const char *delims) {
    int flag = 0;
    int word_start_index = 0, word_len = 0, ind_in_arr = -1;
    int len = strlen(str);

    if (tokens->arr == NULL) {
        int count = 0, end = 1, beg = 0;
        if (tokens->arr == NULL) {
            for (int i = 0; i < len; i++) {
                if ((flag == 0) && checker_not(str, delims, i)) {
                    flag = 1;
                    count++;
                } else if ((flag == 1) && checker_yes(str, delims, i))
                    flag = 0;
            }
            tokens->num = count;
            tokens->arr = (char **) malloc(tokens->num * sizeof(char *));

        }

    } else {
        for (int i = 0; i < len; i++) {
            if ((flag == 0) && checker_not(str, delims, i)) {
                flag = 1;
                ind_in_arr++;
                word_start_index = i;
                word_len++;
                if (str[i + 1] == '\0') {
                    tokens->arr[ind_in_arr] = (char *) malloc((word_len + 1) * sizeof(char));
                    for (int j = 0; j < word_len; j++) {
                        tokens->arr[ind_in_arr][j] = *(str + word_start_index + j);
                    }
                    tokens->arr[ind_in_arr][word_len] = '\0';
                }
            } else if ((flag == 1) && checker_not(str, delims, i)) {
                word_len++;
                if (str[i + 1] == '\0') {
                    tokens->arr[ind_in_arr] = (char *) malloc((word_len + 1) * sizeof(char));
                    for (int j = 0; j < word_len; j++)
                        tokens->arr[ind_in_arr][j] = *(str + word_start_index + j);
                    tokens->arr[ind_in_arr][word_len] = '\0';
                }
            } else if ((flag == 1) && checker_yes(str, delims, i)) {
                flag = 0;
                tokens->arr[ind_in_arr] = (char *) malloc((word_len + 1) * sizeof(char));
                for (int j = 0; j < word_len; j++)
                    tokens->arr[ind_in_arr][j] = *(str + word_start_index + j);
                tokens->arr[ind_in_arr][word_len] = '\0';
                word_len = 0;
            }
        }
    }
}

void tokensFree(Tokens *tokens) {
    for (int i = 0; i < tokens->num; i++)
        free(tokens->arr[i]);
    free(tokens->arr);
}

int splitter() {
    Tokens tokens = {0, NULL};
    char str[1000002];
    char delims[5] = ".,;:";
    scanf("%s", str);
    tokensSplit(&tokens, str, delims);
    tokensSplit(&tokens, str, delims);
    printf("%d\n", tokens.num);
    for (int i = 0; i < tokens.num; i++)
        printf("%s\n", tokens.arr[i]);

    tokensFree(&tokens);
    return 0;
}