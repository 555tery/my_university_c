//
// Created by Egor Kapov on 30.11.2023.
//
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shake_sort(int a[], int N) {
    int left = 1;
    int right = N;
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }
        swapped = 0;
        right--;

        for (int i = right; i > left; i--)
        {
            if (a[i - 1] > a[i])
            {
                swap(&a[i - 1], &a[i]);
                swapped = 1;
            }
        }
        left++;
    }
}

int shakeк_sort() {
    int N;
    scanf("%d", &N);

    int a[100000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    shake_sort(a, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}