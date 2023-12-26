#include <stdio.h>

int one_cnt()
{
    int a, b, count = 0, max = 0;
    scanf("%d", &a);
    for (int i = 0; i < 32; i++){
        b = a & 1;
        a = a >> 1;
        if (b){
            count++;
        }
        else {
            max = max > count ? max : count;
            count = 0;
        }
    }
    max = max > count ? max : count;
    printf("%d", max);
    return 0;
}