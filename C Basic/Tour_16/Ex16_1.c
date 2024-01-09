//
// Created by Egor Kapov on 09.01.2024.
//

#include <stdio.h>

int rusi(){
    int arr[12][10];
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 10; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 10; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}