
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

typedef struct spisok {
    int value;
    struct spisok *next;
    struct spisok *prev;
} spisok;

void spisok_builder(spisok *head) {
    int znachenie = 0;
    spisok *element;
    spisok *tmp;
    scanf("%d", &head->value);
    head->next = NULL;
    head->prev = NULL;
    tmp = head;
    while (scanf("%d", &znachenie) != EOF) {
        element = (spisok *) malloc(sizeof(spisok));
        element->value = znachenie;
        element->next = NULL;
        tmp->next = element;
        element->prev = tmp;
        tmp = element;
    }
    tmp->next = head;
    head->prev = tmp;
}

int main() {
    freopen("/Users/555tery/CLionProjects/my_university_c/Algem/input.txt", "r", stdin);
    freopen("/Users/555tery/CLionProjects/my_university_c/Algem/output.txt", "w", stdout);
    spisok *head;
    int cnt = 1;
    head = (spisok *) malloc(sizeof(spisok));
    spisok *element;
    spisok_builder(head);
    for (*head; head != NULL and cnt < 40;) {
        printf("%d ", head->value);
        element = head;
        head = head->prev;
        cnt++;
    }
}