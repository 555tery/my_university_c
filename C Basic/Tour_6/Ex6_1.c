//
// Created by Egor Kapov on 30.11.2023.
//
#include "stdio.h"

double factorial(double n) {
    double res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

double binominal_coef(double n, double k) {
    double res = 0;
    res = factorial(n) / (factorial(k) * factorial(n - k));
    return res;
}

int binominal_coefficient() {
    // n - stroka, k - index
    double arr[1001][1001];
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    for (int i = 2; i < 1001; ++i) {
        for (int j = 0; j <= i; ++j) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    int number_of_srings = 0;
    scanf("%d", &number_of_srings);
    for (int i = 0; i < number_of_srings; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%0.10g\n", arr[a][b]);
    }
}