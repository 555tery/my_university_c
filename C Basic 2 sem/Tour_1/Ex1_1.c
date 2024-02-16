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
    int num_of_test = 0;
    scanf("%d", &num_of_test);
    char bufer1[50], bufer2[50];
    for (int i = 0; i < num_of_test; ++i) {
        gets(bufer1);
        gets(bufer2);
        char *now = strtok(bufer1, " ");
        while (now != NULL){
            sscanf(now, ^N, )

        }
    }
}
//
//1
//O( 1 )
//O( logN )


//O( N^2 )
