//
// Created by Egor Kapov on 31.10.2023.
//

#include "stdio.h"

int TestFileForStudy() {
    int arr1[101], arr2[101], size = 0, counter = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < size; ++i) {
        if (arr1[i] % 2 == 0) {
            arr2[counter] = arr1[i];
            counter++;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (arr1[i] % 2 == 1) {
            arr2[counter] = arr1[i];
            counter++;
        }
    }
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr2[i]);
    }
    return 0;
}