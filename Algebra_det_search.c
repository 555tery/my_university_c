//
// Created by Egor Kapov on 30.10.2023.
//

#include <stdio.h>

int main() {
    float arr[200][200], det = 0, reserv_stroka[200];
    int size = 0, flag = 0, naturale_stroka = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%f", &arr[i][j]);
        }
    }
//  for (int i = 0; i < size; ++i) {
//      for (int j = 0; j < size; ++j) {
//          printf("%.2f ", arr[i][j]);
//      }
//      printf("\n");
//  }
    for (int i = 0; i < size; ++i) {
        if (arr[i][1] != 0)

    }


}