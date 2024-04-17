
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int num_of_jews, every_n_jew;
typedef struct spisok {
    int value;
    struct spisok *next;
    struct spisok *prev;
} spisok;

spisok *spisok_builder(spisok *head) {
    spisok *element;
    spisok *tmp;
    int znachenie;
    scanf("%d", &head->value);
    while (scanf("%d", &znachenie) != EOF) {
        tmp = head;
        element = (spisok *) malloc(sizeof(spisok));
        element->next = NULL;
        element->prev = NULL;
        element->value = znachenie;
        while (1)
            if (element->value > head->value) {
                head->prev = element;
                element->next = head;
                head = element;
                break;
            } else if (tmp->next == NULL) {
                element->prev = tmp;
                tmp->next = element;
                break;
            }else if (tmp->value >= element->value and tmp->next->value <= element->value  ) {
                element->next = tmp->next;
                tmp->next = element;
                break;
            }  else tmp = tmp->next;

    }
    return head;
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
    spisok *head, *tmp;
    int cnt = 1;

    scanf("%d %d", &num_of_jews, &every_n_jew);
    head = (spisok *) malloc(sizeof(spisok));
    head->next = NULL;
    head->prev = NULL;
    head = spisok_builder(head);
    while (1) {
        printf("%d ", head->value);
        if (head->next == NULL)
            break;
        tmp = head;
        head = head->next;
        cnt++;
        free(tmp);
    }
    free(head);
}