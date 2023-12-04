//
// Created by Egor Kapov on 05.12.2023.
//

#include "stdio.h"

void code_style() {
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_7/input.txt", "r", stdin);
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_7/output.txt", "w", stdout);
    char symbol;
    int flag = 1, cnt = 0, res = 0;
    while (scanf("%c", &symbol)!=EOF) {

        if (symbol == '\n') {
            flag = 1;
            cnt = 0;
            //printf("lol\n");
        }
        if (symbol > ' ') {
            res += cnt;
            flag = 0;
            cnt=0;
            //printf("lol2\n");

        }
        if (flag == 1 && symbol == ' ')
            cnt++;
    }
    printf("%d", res);
    fclose(stdout);
    fclose(stdin);
}