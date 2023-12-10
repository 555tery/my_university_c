//
// Created by Egor Kapov on 31.10.2023.
//
#include "stdio.h"

int alphabet() {
    char arr[23];
    int arrr[2];
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_5/1.txt", "r", stdin);
    for (int i = 0; i < 2; ++i) {
        arrr[i] = 0;
    }
    int hod = 0;
    char bukva = 'a';
    while (scanf("%s", arr) ==1) {
        int flag = 0;
        for (int i = 0; arr[i] != '\0'; ++i) {
            if (arr[i] == bukva) {
                ++arrr[hod % 2];
                flag = 1;
                break;
            }
        }
        hod++;
        bukva++;
        if (flag == 0){
            arrr[hod%2]++;
            break;
        }
    }

    if (arrr[0] > arrr[1])
        printf("PLAYER 1");
    if (arrr[0] < arrr[1])
        printf("PLAYER 2");
    if (arrr[0] == arrr[1])
        printf("NO WINNER");
    freopen("/Users/555tery/CLionProjects/my_university_c/C Basic/Tour_5/our.txt", "w", stdout);
}