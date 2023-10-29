//
// Created by Egor Kapov on 30.10.2023.
//

#include <stdio.h>

int main() {
    double a1, a2, a3,
            b1, b2, b3,
            c1, c2, c3;
    int flag = 0;
    double res = 0, det;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a1, &a2, &a3, &b1, &b2, &b3, &c1, &c2, &c3);
    det = a1 * b2 * c3 + c1 * a2 * b3 + b1 * c2 * a3 - a3 * b2 * c1 - a1 * c2 * b3 - a2 * b1 * c3;
    if (det != 0)
        printf("false\n");
    else
        printf("true\n");

    if (a2 * b3 - a3 * b2 == 0 && a3 * b1 - a1 * b3 == 0 && a1 * b2 - a2 * b1 == 0) {
        flag = 1;
        printf("%.2lf %.2lf %.2lf\n", a1, a2, a3);
        printf("%.2lf %.2lf %.2lf\n", b1, b2, b3);
    }
    if (b2 * c3 - b3 * c2 == 0 && b3 * c1 - b1 * c3 == 0 && b1 * c2 - b2 * c1 == 0) {
        if (flag == 1) {
            printf("%.2lf %.2lf %.2lf\n", c1, c2, c3);
        } else {
            printf("%.2lf %.2lf %.2lf\n", b1, b2, b3);
            printf("%.2lf %.2lf %.2lf\n", c1, c2, c3);
            flag = 1;
        }
    }
    if (flag == 0)
        if (a2 * c3 - a3 * c2 == 0 && a3 * c1 - a1 * c3 == 0 && a1 * c2 - a2 * c1 == 0) {
            printf("%.2lf %.2lf %.2lf\n", a1, a2, a3);
            printf("%.2lf %.2lf %.2lf\n", c1, c2, c3);
        }
}