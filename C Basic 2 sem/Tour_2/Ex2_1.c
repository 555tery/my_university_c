#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "iso646.h"

struct list {
    int data;
    struct list *next; // создаем список
};
typedef struct stack {
    struct list *top;  // создаем стракт стек
} Stack;

Stack *create() {
    Stack *S;
    S = (Stack *) malloc(sizeof(Stack));
    S->top = NULL;
    return S;               // функция создания стека
}

void makenull(Stack *S) {
    while (S->top) {
        struct list *p = S->top;
        S->top = p->next;           //
        free(p);
    }
}

int empty(Stack *S) {
    return (S->top == NULL);
}

int top(Stack *S) {
    return (S->top->data);
}

int pop(Stack *S) {
    int a;
    struct list *p;
    p = S->top;
    a = p->data;
    S->top = p->next;
    free(p);
    return a;
}

void push(Stack *S, int a) {
    struct list *p;
    p = (struct list *) malloc(sizeof(struct list));
    p->data = a;
    p->next = S->top;
    S->top = p;
}
int inf_post(){

}
