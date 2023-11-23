
//
// Created by Egor Kapov on 23.11.2023.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct spisok {
    int value;
    struct spisok *next;
} spisok;

int spisok_hvost() {
    spisok *head;
    int znachenie = 0;
    int count = 0, sum = 0;
    spisok *element;
    spisok *gde_ya;
    gde_ya = (spisok *) malloc(sizeof(spisok));
    head = (spisok *) malloc(sizeof(spisok));
    scanf("%d", &head->value);
    head->next = NULL;
    gde_ya = head;
    while (scanf("%d", &znachenie) != EOF) {
        element = (spisok *) malloc(sizeof(spisok));
        element->value = znachenie;
        element->next = NULL;
        gde_ya->next = element;
        gde_ya = element;
    }
    for (*head; head != NULL;) {
        //printf("%d\n",head->value);
        count++;
        sum += head->value;
        element = head;
        head = head->next;
        free(element);
    }
    printf("%d", sum / count);
}