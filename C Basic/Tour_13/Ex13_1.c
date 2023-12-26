#include <stdio.h>
#include <stdlib.h>


void quicksort(int *arr, int n){ // справа оставим элементы больше mid, слева -- меньше
    int i = 0, j = n - 1, mid = arr[n / 2], tmp;
    while (i <= j){
        while(arr[i] < mid){
            i++;
        }
        while (arr[j] > mid){
            j--;
        }
        if (i <= j){
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (j > 0){
        quicksort(arr, j + 1); // слева
    }
    if (i < n){
        quicksort(&arr[i], n - i); // справа
    }
}


int qusort()
{
    int n, *arr;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quicksort(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}