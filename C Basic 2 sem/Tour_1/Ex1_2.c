#include <stdio.h>
#include <stdlib.h>


typedef struct Dict {
    int key;
    char value[8];
} dictionary;


typedef struct Buf {
    dictionary *arr;
    int current;
    int capacity;
} buffer;


void new(buffer *a, dictionary elem) {
    if (a->capacity <= a->current) {
        a->capacity += 1;
        a->arr = realloc(a->arr, a->capacity * sizeof(buffer));
    }
    a->arr[(a->current)++] = elem;
}


int rost_mas() {
    buffer *a;
    a = (buffer *) malloc(sizeof(buffer) * 1000010);
    for (int i = 0; i < 1000010; i++) {
        a[i].current = 0;
        a[i].capacity = 1;
        a[i].arr = (dictionary *) malloc(sizeof(dictionary));
    }

    int n;
    scanf("%d", &n);
    dictionary elem;
    for (int i = 0; i < n; i++) {
        scanf("%d%s", &elem.key, elem.value);
        new(&a[elem.key], elem);
    }
    for (int i = 0; i < 1000010; i++) {
        for (int j = 0; j < a[i].current; j++) {
            printf("%d %s\n", (a[i].arr)[j].key, (a[i].arr)[j].value);
        }
    }
    for (int i = 0; i < 1000010; ++i) {
        free(a[i].arr);
    }
    free(a);
    return 0;

}