//
// Created by Egor Kapov on 27.12.2023.
//
#include "stdio.h"
#include "limits.h"
int reverse(){
    int a = 0;
    scanf("%d", &a);
    int res = 0;
    unsigned int bignum = 1;
    bignum <<= (CHAR_BIT*sizeof(unsigned int)-1);
    for (int i = 0; i < CHAR_BIT*sizeof(unsigned int); ++i) {
        if ((bignum & a) == bignum)
            printf("1");
        else printf("0");
        bignum>>=1;
    }
    printf("\n");
    bignum = 1;
    for (int i = 0; i < CHAR_BIT*sizeof(unsigned int); ++i) {
        res <<= 1;
        if ((bignum & a) == bignum)
            res++;
        bignum<<=1;
    }
    printf("%d", res);
    printf("\n");
  bignum = 1;


    for (int i = 0; i < CHAR_BIT*sizeof(unsigned int); ++i) {
        if ((bignum & a) == bignum)
            printf("1");
        else printf("0");
        bignum<<=1;
    }

}