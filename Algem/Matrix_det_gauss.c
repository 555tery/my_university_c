#include <stdio.h>

int Matrix_det_gauss() {
    float arr[200][200];
    int size = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%f", &arr[i][j]);
        }
    }
    float res = 0;
    float det = 1;
    float znak = 1;
    for (int i = 0; i < size; i++) {
        if (arr[i][i] == 0) {
            int stroka = -1;
            for (int j = i + 1; j < size; j++) {
                if (arr[j][i] != 0) {
                    stroka = j;
                    break;
                }
            }
            if (stroka == -1) {
                return 0;
            }
            for (int f = 0; f < size; f++) {
                float temp = arr[i][f];
                arr[i][f] = arr[stroka][f];
                arr[stroka][f] = temp;
            }
            znak *= -1;
        }
        det *= arr[i][i];
        for (int j = i + 1; j < size; j++) {
            float ratio = arr[j][i] / arr[i][i];
            for (int k = i; k < size; k++) {
                arr[j][k] -= ratio * arr[i][k];
            }
        }
    }
    res = det * znak;
    printf("%.2f", res);
    return 0;
}

