
#include <stdio.h>

double ABS(double a) {
    if (a > 0)
        return a;
    else if (a < 0)
        return -a;
}
int arctg_taylor() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int del = 1, n=0;
    double x, e, result, y, s;
    scanf("%lf %lf", &x, &e);
    s = x;
    y = x;
    result = x;
    while (e < ABS(y))
    {
        s = s * x * x;
        if (n == 0) {
            y = -1 * (s / (del + 2));
            n = 1;
        }
        else {
            y = ((s) / (del + 2));
            n = 0;
        }
        result += y;
        del = del + 2;
    }
    printf("%0.5lf", result);
    return 0;
}