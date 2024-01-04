//
// Created by Egor Kapov on 03.01.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int sufler() {
    int len = 0, students_num = 0, suspicion_lim = 0, suspicion = 0, max_suspicion, sufler_flag = 0;
    scanf("%d %d %d", &len, &students_num, &suspicion_lim);
    char *right_ans, *now_ans;
    int *res;
    res = (int*) malloc(sizeof(int)*students_num);
    right_ans = (char *) malloc(sizeof(char) * (len + 1));
    now_ans = (char *) malloc(sizeof(char) * (len + 1));
    scanf("%s", right_ans);
    for (int i = 0; i < students_num; ++i) {
        scanf("%s", now_ans);
        suspicion = 0;
        max_suspicion = 0;
        for (int j = 0; j < len; ++j) {
            if (right_ans[j] != now_ans[j])
                suspicion++;
            else {
                if (max_suspicion < suspicion)
                    max_suspicion = suspicion;
                suspicion = 0;
            }
        }
        if (max_suspicion< suspicion)
            max_suspicion = suspicion;
        res[i] = max_suspicion;
        if (max_suspicion >= suspicion_lim)
            sufler_flag++;
    }
    for (int i = 0; i < students_num; ++i) {
        printf("%d\n", res[i]);
    }
    if (sufler_flag)
        printf("YES");
    else
        printf("NO");
}
//4 3 2
//baby
//ball
//bold
//babe