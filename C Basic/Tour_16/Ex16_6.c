//
// Created by Egor Kapov on 09.01.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"

int chisla() {
    unsigned int res = 0, test_num = 0, opened = 0, cnt = 0, cnt1 = 0, flag2 = 0, closed, super_cnt = 0;
    char now = 0;
    scanf("%d\n", &test_num);
    for (int i = 0; i < test_num; ++i) {
        unsigned int res_table[125] = {0};
        opened = 0, res = 0, cnt = 0, cnt1 = 0, flag2 = 0, super_cnt = 0, closed =0;
        scanf("%c", &now);
        while (now != '\n') {
            if (now == '(')
                opened++;
            else if (now == ')'){
                closed++;
                if (opened < closed)
                    flag2++;
            }
            else if (now > 96 and now < 123) {
                res_table[now]++;
                cnt1++;
                if (opened == 0)
                    flag2++;
                if (closed)
                    flag2++;
                if (cnt1 != cnt +1)
                    flag2++;
            } else if (now == ','){
                cnt++;
                if (opened == 0)
                    flag2++;
                if (closed)
                    flag2++;
                if (cnt1 != cnt)
                    flag2++;
            }
            else
                super_cnt++;
            scanf("%c", &now);
        }
        for (int j = 97; j < 123; ++j) {
            if (res_table[j] > 1) {
                flag2++;
            } else if (res_table[j]) {
                res += (1 << (j - 97));
            }
        }
        if ((opened == 1 and opened == closed) and ((cnt1 == cnt + 1) or (cnt == 0 and cnt1 == 0)) and flag2 == 0 and super_cnt ==0)
            printf("%08X\n", res);
        else printf("Incorrect\n");
    }


}