
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int num_of_jews, every_n_jew;
typedef struct spisok {
    int value;
    struct spisok *next;
    struct spisok *prev;
} spisok;

void spisok_builder(spisok *head) {
    spisok *element;
    spisok *tmp;
    head->next = NULL;
    head->prev = NULL;
    tmp = head;
    head->value = 1;
    for (int znachenie = 2; znachenie <= num_of_jews; ++znachenie) {
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

void deleter(spisok *elem) {
    spisok *tmp = elem;
    elem = elem->next;
    elem->prev = tmp->prev;
    tmp->prev->next = elem;
    if (elem->next == elem and elem->prev == elem) {
        elem->prev = NULL;
        elem->next = NULL;
    } else free(tmp);
}

int main() {
    freopen("/Users/555tery/CLionProjects/my_university_c/Algem/input.txt", "r", stdin);
    freopen("/Users/555tery/CLionProjects/my_university_c/Algem/output.txt", "w", stdout);
    spisok *head;
    int cnt = 1;
    scanf("%d %d", &num_of_jews, &every_n_jew);
    head = (spisok *) malloc(sizeof(spisok));
    spisok *element;
    spisok_builder(head);
    for (*head; head->next != NULL;) {
//        printf("%d ", head->value);
        element = head;
        head = head->next;
        if (cnt % every_n_jew == 0)
            deleter(head->prev);
//        element->next = NULL;
        cnt++;

    }
    printf("%d", head->value);
    free(head);
}