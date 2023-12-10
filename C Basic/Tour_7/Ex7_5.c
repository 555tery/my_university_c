//
// Created by Egor Kapov on 05.12.2023.
//
#include "stdio.h"

void bukovi_counter() {
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_7/input.txt", "r", stdin);
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_7/output.txt", "w", stdout);
    int line_num = 1, chars_cnt = 0, letters_ccnt = 0, lower_cnt = 0, upper_cnt = 0, digits_cnt = 0;
    char symbol;
    while (scanf("%c", &symbol) == 1) {
        chars_cnt++;
        if (symbol > 47 && symbol < 58) {
            digits_cnt++;
        }

        if (symbol > 64 && symbol < 91) {
            upper_cnt++;
        }

        if (symbol > 96 && symbol < 123) {
            lower_cnt++;
        }

        if (symbol == '\n') {
            chars_cnt--;
            letters_ccnt = upper_cnt + lower_cnt;
            printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", line_num, chars_cnt,
                   letters_ccnt, lower_cnt, upper_cnt, digits_cnt);
            line_num++;
            chars_cnt = 0, letters_ccnt = 0, lower_cnt = 0, upper_cnt = 0, digits_cnt = 0;
        }
    }
    printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.", line_num, chars_cnt,
           letters_ccnt, lower_cnt, upper_cnt, digits_cnt);

    fclose(stdout);
    fclose(stdin);
}

