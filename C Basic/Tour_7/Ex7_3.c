//
// Created by Egor Kapov on 05.12.2023.
//

#include "stdio.h"

void code_style() {
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_7/input.txt", "r", stdin);
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_7/output.txt", "w", stdout);
    char symbol;
    int flag = 1, cnt = 0;
    while (scanf("%c", &symbol)==1) {
        if (symbol > 31)
            flag = 0;
        if (symbol == 13)
            flag = 1;
        if (flag == 1 && symbol == 32)
            cnt++;
    }
    printf("%d", cnt);
    fclose(stdout);
    fclose(stdin);
}