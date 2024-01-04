//
// Created by Egor Kapov on 27.12.2023.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct spisok {
    int value;
    struct spisok *next;
} spisok;

//int partition(int *arr, int num, int pi) {
//    spisok *element;
//    int znachenie = 0, cnt = 0, flag = 0;
//    spisok *head, *tail;
//    head = (spisok *) malloc(sizeof(spisok));
//    head->next = NULL;
//    tail = head;
//    for (int i = 0; i < num; i++) {
//        znachenie = arr[i];
//        printf("%d\n", znachenie);
//        element = (spisok *) malloc(sizeof(spisok));
//        if (znachenie < pi || ((znachenie == pi) && (flag % 2 == 0))) {
//            if (i == 0)
//                head->value = znachenie;
//            else {
//                element->value = znachenie;
//                element->next = head;
//                head = element;
//            }
//            cnt++;
//            if (znachenie == pi)
//                flag++;
//        } else if (znachenie > pi || ((znachenie == pi) && (flag % 2 == 1))) {
//            if (i == 0)
//                head->value = znachenie;
//            else {
//                element->value = znachenie;
//                element->next = NULL;
//                tail->next = element;
//                tail = element;
//            }
//            if (znachenie == pi)
//                flag++;
//        }
//    }
//    for (int i = 0; i < num; ++i) {
//        arr[i] = head->value;
//        element = head;
//        head = head->next;
//        free(element);
//    }
//    return cnt;
//}


int massive_split() {
    FILE *in = fopen("input.bin", "rb"), *out = fopen("output.bin", "wb");
    int num, pi;
    fread(&num, sizeof(int), 1, in);
    fread(&pi, sizeof(int), 1, in);
    spisok *element;
    int znachenie = 0, cnt = 0, flag = 0;
    spisok *head, *tail;
    head = (spisok *) malloc(sizeof(spisok));
    head->next = NULL;
    tail = head;
    for (int i = 0; i < num; i++) {
        fread(&znachenie, sizeof(int), 1, in);
        element = (spisok *) malloc(sizeof(spisok));
        if (znachenie < pi || ((znachenie == pi) && (flag % 2 == 0))) {
            if (i == 0)
                head->value = znachenie;
            else {
                element->value = znachenie;
                element->next = head;
                head = element;
            }
            cnt++;
            if (znachenie == pi)
                flag++;
        } else if (znachenie > pi || ((znachenie == pi) && (flag % 2 == 1))) {
            if (i == 0)
                head->value = znachenie;
            else {
                element->value = znachenie;
                element->next = NULL;
                tail->next = element;
                tail = element;
            }
            if (znachenie == pi)
                flag++;
        }
    }
    fwrite(&cnt, sizeof(int), 1, out);

    for (int i = 0; i < num; ++i) {
        fwrite(&head->value, sizeof(int), 1, out);
        element = head;
        head = head->next;
        free(element);
    }
    fclose(in);
    fclose(out);
    return 0;
}