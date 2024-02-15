//
// Created by Egor Kapov on 12.02.2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"
#include "string.h"


//
//int find(char arr[]) {
//    int exp_flag = 0, log_flag = 0, pokaz_flag = 0, start_flag = 0;
//    for (int i = 0; i < 98; ++i) {
//        if (arr[i] == '(')
//            start_flag = 1; // начали считывание всего
//        else if (arr[i] - '0' <= 9 and arr[i] - '0' >= 0 and arr[i - 1] == ' ') { // начали считываение показательной
//            pokaz_flag = 1;
//            if (pokaz_flag == 1 and )
//        }
//
//    }
//}
typedef struct Res {
    char exp[8];
    char pokaz[8];
    char log[8];
} Res;

int assimpot() {
    int num_of_tests = 0;
    scanf("%d\n", &num_of_tests);
    for (int i = 0; i < num_of_tests; ++i) {
        char stroka_1[100] = {0}, stroka_2[100] = {0};
        Res res1, res2;
//       ®   res1.log[i] = 'Z', res1.exp[i] = 'Z', res1.pokaz[i] = 'Z', res2.log[i] = 'Z', res2.exp[i] = 'Z', res2.pokaz[i] = 'Z';
        gets(stroka_1); // приняли первую строку из сравнения
        gets(stroka_2); // приняли вторую строку из сравнения
        if (strcmp(stroka_1, stroka_2) == 0) {
            printf("0\n");
        } else if (strcmp(stroka_1, "O( 1 )") == 0) {
            printf("1\n");
        } else if (strcmp(stroka_2, "O( 1 )") == 0) {
            printf("-1\n");
        } else {
            char *gde;
            int j = 0;
            if (strstr(stroka_1, " logN ") != NULL)
                res1.log[0] = 1;
            if (strstr(stroka_2, " logN ") != NULL)
                res2.log[0] = 1;
            if (strstr(stroka_1, " N "))
                res1.pokaz[0] = 1;
            if (strstr(stroka_2, " N "))
                res2.pokaz[0] = 1;

            gde = strstr(stroka_1, " N^");
            if (gde != NULL) {
                while (*gde != ' ') {
                    gde++;
                    res1.pokaz[j] = *gde;
                    j++;
                }
            }
            j = 0;
            gde = strstr(stroka_1, " logN^");
            if (gde != NULL) {
                while (*gde != ' ') {
                    gde++;
                    res1.log[j] = *gde;
                    j++;
                }
            }
            j = 7;
            gde = strstr(stroka_1, "^N ");
            if (gde != NULL) {
                while (*gde != ' ') {
                    gde--;
                    res1.exp[j] = *gde;
                    j--;
                }
            }

            j = 0;
            gde = strstr(stroka_2, " N^");
            if (gde != NULL) {
                while (*gde != ' ') {
                    gde++;
                    res2.pokaz[j] = *gde;
                    j++;
                }
            }
            j = 0;
            gde = strstr(stroka_2, " logN^");
            if (gde != NULL) {
                while (*gde != ' ') {
                    gde++;
                    res2.log[j] = *gde;
                    j++;
                }
            }
            j = 7;
            gde = strstr(stroka_2, "^N ");
            if (gde != NULL) {
                while (*gde != ' ') {
                    gde--;
                    res2.exp[j] = *gde;
                    j--;
                }
            }

            printf("O( %s^N N^%s logN^%s )\n", res1.exp, res1.pokaz, res1.log);
            printf("O( %s^N N^%s logN^%s )\n", res2.exp, res2.pokaz, res2.log);
        }
    }
}

