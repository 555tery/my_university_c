#include "stdio.h"
#include "stdlib.h"

typedef struct spisok {
    int value;
    struct spisok *next;
} spisok;

void vstavka(spisok **head, int znachenie) {
    spisok *element = (spisok *) malloc(sizeof(spisok));
    element->value = znachenie;
    spisok *now;
    now = *head;
    if (now->value == znachenie)
        return;
    if (znachenie < (*head)->value) {
        element->next = *head;
        *head = element;
    } else {
        now = *head;
        while (now->next != NULL) {
            if (now->value == znachenie)
                break;
            if (now->value < znachenie && now->next->value > znachenie) {
                element->next = now->next;
                now->next = element;
                break;
            }
            now = now->next;
        }
        if (now->next == NULL) {
            if (now->value == znachenie)
                return;
            now->next = element;
            element->next = NULL;
        }

    }
}

int sort_spisok() {
    spisok *head;
    int znachenie = 0;
    head = (spisok *) malloc(sizeof(spisok));
    head->next = NULL;
    scanf("%d", &head->value);
    while (scanf("%d", &znachenie) != EOF) {
        vstavka(&head, znachenie);
    }
    spisok *elem;
    for (*head; head != NULL;) {
        printf("%d ",head->value);
        elem = head;
        head = head->next;
        free(elem);
    }
}