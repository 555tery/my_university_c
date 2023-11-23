//
// Created by Egor Kapov on 23.11.2023.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct spisok {
    int value;
    struct spisok *next;
} spisok;

int spisok_golova() {
    spisok *head;
    int znachenie = 0;
    int count = 0;
    spisok *element;
    head = (spisok *) malloc(sizeof(spisok));
    scanf("%d", &head->value);
    head->next = NULL;
    while (scanf("%d", &znachenie) != EOF) {
        element = (spisok *) malloc(sizeof(spisok));
        element->value = znachenie;
        element->next = head;
        head = element;
    }
    for (*head; head != NULL;) {
        //printf("%d\n",head->value);
        if (head->value < 0 && head->value % 7 == 0)
            count++;
        element = head;
        head = head->next;
        free(element);
    }
    printf("%d", count);
}