//
// Created by Egor Kapov on 09.01.2024.
//

#include "stdio.h"
#include "iso646.h"
#include "stdlib.h"
#include <math.h>

typedef struct _item {
    long long int weight;
    long long int cost;
} item;

int backpack_test() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "weight", stdout);
    int num;
    long long int weight;
    item **all;
    scanf("%d %lld", &num, &weight);
    all = (item **) malloc((1+num) * sizeof(item *));
    for (int i = 0; i < num; i++) {
        all[i] = (item *) malloc(sizeof(item));
        scanf("%lld %lld", &all[i]->weight, &all[i]->cost);
    }
    item maxi, now;
    int M = 0, res_counter = 0, counter_now = 0;
    maxi.weight = 0;
    maxi.cost = 0;
    now.weight = 0;
    now.cost = 0;
    for (int i = 1; i < 1 << num; i++) {
        for (int j = 0; j < num; j++) {
            if ((i & (1 << j))) {
                now.weight += all[j]->weight;
                now.cost += all[j]->cost;
                counter_now++;
            }
        }
        if (now.weight > weight) {
            now.cost = 0;
            now.weight = 0;
            counter_now = 0;
            continue;
        }
        if (now.cost > maxi.cost) {
            maxi.cost = now.cost;
            maxi.weight = now.weight;
            M = i;
            res_counter = counter_now;
        }
        now.cost = 0;
        now.weight = 0;
        counter_now = 0;
    }
    printf("%lld %d\n", maxi.cost, res_counter);
    for (int i = 0; i < num; i++) {
        if ((M >> i) & 1) {
            printf("%d ", i + 1);
        }
    }
    free(all);
    return 0;
}