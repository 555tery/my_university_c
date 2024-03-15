
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"


int ab(int N) {
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}

int Prost_matrix() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int cnt = 0;
    int *prost = (int *) calloc(520, sizeof(int));
    for (int i = 0; i < 3700; ++i) {
        if (ab(i)) {
            prost[cnt] = i;
            cnt++;
        }
    }
    int num = 0, res = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            printf("%d ", prost[i + j]);
            res += prost[i + j];
        }
        printf("\n");
    }
    printf("%d", res);
    free(prost);
    return 0;
}