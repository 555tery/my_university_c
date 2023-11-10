//
// Created by Egor Kapov on 09.11.2023.
//
#include "stdio.h"
#include "string.h"

typedef struct Label_s {
    char name[16]; //имя автора (заканчивается нулём)
    int age; //возраст автора (сколько лет)
} Label;
typedef struct NameStats_s {
    int cntTotal; //сколько всего подписей
    int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats;
typedef struct AgeStats_s {
    int cntTotal;
    int cntAdults;
    int cntKids;
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges) {
    (*oNames).cntLong = 0;
    (*oAges).cntAdults = 0;
    (*oAges).cntKids = 0;
    (*oAges).cntTotal = 0;
    (*oNames).cntTotal = 0;
    for (int i = 0; i < cnt; ++i) {
        if (strlen(arr[i].name) > 10) {
            (*oNames).cntLong++;
        }
        if (arr[i].age >= 18) {
            (*oAges).cntAdults++;
        } else if (arr[i].age < 14) {
            (*oAges).cntKids++;
        }
        (*oAges).cntTotal++;
        (*oNames).cntTotal++;
    }

}

int Ages_and_names() {
    Label arr[1010];
    int number = 0;
    char s[6000];
    NameStats name_stats;
    AgeStats age_stats;
    scanf("%d\n", &number);
    for (int i = 0; i < number; ++i) {
        gets(s);
        sscanf(s, "%s %d let\n", arr[i].name, &arr[i].age);
    }
    calcStats(arr, number, &name_stats, &age_stats);
    printf("names: total = %d\n", name_stats.cntTotal);
    printf("names: long = %d\n", name_stats.cntLong);
    printf("ages: total = %d\n", age_stats.cntTotal);
    printf("ages: adult = %d\n", age_stats.cntAdults);
    printf("ages: kid = %d", age_stats.cntKids);т
}