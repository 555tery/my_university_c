//
// Created by Egor Kapov on 12.02.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"
#include "string.h"

typedef struct Res {
    float v_step;
    float v_osn;
    float vlog;
} Res;

int assimpot() {
    int num_of_tests = 0;
    scanf("%d\n", &num_of_tests);
    for (int i = 0; i < num_of_tests; ++i) {
        Res res1, res2;
        res1.v_step = 1;
        res1.v_osn = 0;
        res1.vlog = 0;
        res2.v_step = 1;
        res2.v_osn = 0;
        res2.vlog = 0;
        char bufer1[50] = {0};
        char bufer2[50] = {0};
        gets(bufer1);
        gets(bufer2);
        char *s1, *s2;
        if (strstr(bufer1, " N ") != NULL)
            res1.v_osn = 1;
        if (strstr(bufer2, " N ") != NULL)
            res2.v_osn = 1;
        if (strstr(bufer1, " logN ") != NULL)
            res1.vlog = 1;
        if (strstr(bufer2, " logN ") != NULL)
            res2.vlog = 1;
        s1 = strtok(bufer1, " ");
        while (s1 != NULL) {
            sscanf(s1, "logN^%f", &res1.vlog);
            sscanf(s1, "N^%f", &res1.v_osn);
            sscanf(s1, "%f^N", &res1.v_step);
            s1 = strtok(NULL, " ");
        }
        s1 = strtok(bufer2, " ");
        while (s1 != NULL) {
            sscanf(s1, "logN^%f", &res2.vlog);
            sscanf(s1, "N^%f", &res2.v_osn);
            sscanf(s1, "%f^N", &res2.v_step);
            s1 = strtok(NULL, " ");
        }
        if (res1.v_step > res2.v_step)
            printf("1\n");
        else if (res1.v_step < res2.v_step)
            printf("-1\n");
        else if (res1.v_step == res2.v_step) {
            if (res1.v_osn > res2.v_osn)
                printf("1\n");
            else if (res1.v_osn < res2.v_osn)
                printf("-1\n");
            else if (res1.v_osn == res2.v_osn) {
                if (res1.vlog > res2.vlog)
                    printf("1\n");
                else if (res1.vlog < res2.vlog)
                    printf("-1\n");
                else if (res1.vlog == res2.vlog) {
                    printf("0\n");
                }
            }
        }

    }
}


