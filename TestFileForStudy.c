
#include "stdio.h"
#include "stdlib.h"
#include "iso646.h"
#include "string.h"

typedef struct ind {
    char ind_name[30];
    int ind_value;
} ind;
//

int num_of_ind = 0;
char stroka[300];
char service[] = "()+-*/";
ind *id_list;

void scanner_ind() {
    scanf("%d", &num_of_ind);
    id_list = (ind *) malloc(num_of_ind * sizeof(ind));
    for (int i = 0; i < num_of_ind; ++i) {
        scanf("%s", id_list->ind_name);         // scanner is good
        scanf("%d", &id_list[i].ind_value);
    }
    scanf("%s", stroka);
}

//
//int poisk_podstorki(char* origin, char* nado_naiti){
//   char res[300];
//    for (int i = 0; i < strlen(origin); ++i) {
//        for (int j = 0; j < strlen(nado_naiti); ++j) {
//            if (origin[i+j] != nado_naiti[j]){
//                res[i] = origin[i];
//                break;
//            }
//
//        }
//    }
//}
//
//int test(char a, char b) {
//    if ((a == '-' or a == '*' or a == '+' or a == '/') and (b == '-' or b == '*' or b == '+' or b == '/'))
//        return 0;
//}
//
//void changer() {
//    char *new[1000];
//    for (int i = 1; i < strlen(stroka); ++i) {
//        for (int j = 0; j < num_of_ind; ++j) {
//            if (stroka[i] == )
//        }
//    }
//
//}
//


void add_to_stack(char a) {

}

typedef struct stack {
    char arr[100];
    int cnt;
} stack;

int TestFileForStudy() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

}