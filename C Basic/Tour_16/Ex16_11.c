//
// Created by Egor Kapov on 04.01.2024.
//
#include "math.h"

#define N 201

#include "stdio.h"

int sle_sol() {
    double mas[N][N + 1];
    double x[N];
    int otv[N];
    int i, j, k, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%lf", &mas[i][j]);
        scanf("%lf", &mas[i][n]);
    }
//    for (int l = 0; l < n; ++l) {
//        scanf("%lf", &mas[l][n]);
//    }
    for (i = 0; i < n + 1; i++)
        otv[i] = i;
    for (k = 0; k < n; k++) {
        int f, g, i_max = k, j_max = k;
        double temp;
        for (f = k; f < n; f++)
            for (g = k; g < n; g++)
                if (fabs(mas[i_max][j_max]) < fabs(mas[f][g])) {
                    i_max = f;
                    j_max = g;
                }
        for (g = k; g < n + 1; g++) {
            temp = mas[k][g];
            mas[k][g] = mas[i_max][g];
            mas[i_max][g] = temp;
        }
        for (f = 0; f < n; f++) {
            temp = mas[f][k];
            mas[f][k] = mas[f][j_max];
            mas[f][j_max] = temp;
        }
        f = otv[k];
        otv[k] = otv[j_max];
        otv[j_max] = f;
        for (j = n; j >= k; j--)
            mas[k][j] /= mas[k][k];
        for (i = k + 1; i < n; i++)
            for (j = n; j >= k; j--)
                mas[i][j] -= mas[k][j] * mas[i][k];
    }
    for (i = 0; i < n; i++)
        x[i] = mas[i][n];
    for (i = n - 2; i >= 0; i--)
        for (j = i + 1; j < n; j++)
            x[i] -= x[j] * mas[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == otv[j]) {
                printf("%.8f\n", x[j]);
                break;
            }
    return 0;
}
