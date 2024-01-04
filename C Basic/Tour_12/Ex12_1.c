//
// Created by Egor Kapov on 02.01.2024.
//
#include "stdio.h"
#include "iso646.h"
#include "stdlib.h"


void permut_to_invtab(int a[], int b[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt = 0;
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[i])
                cnt++;
        }
        b[a[i]-1] = cnt;
    }
}


int invers_table() {
    int len = 0;
    scanf("%d", &len);
    int *baza;
    int *res;
    res = (int *) malloc(sizeof(int) * len);
    baza = (int *) malloc(sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        scanf("%d", &baza[i]);
    }
    permut_to_invtab(baza, res, len);
    for (int i = 0; i < len; ++i) {
        printf("%d ", res[i]);
    }
}