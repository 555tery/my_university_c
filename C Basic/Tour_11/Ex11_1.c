//
// Created by Egor Kapov on 23.11.2023.
//
#include "stdio.h"
#include "stdint.h"

int binar_slojenie(){
    FILE* input = fopen("input.bin", "rb");
    FILE* output = fopen("output.bin", "wb");
    int32_t a,b, res;
    int64_t c;
    fread(&a, sizeof(int32_t), 1, input);
    fread(&b, sizeof(int32_t), 1, input);
    c = ((int64_t) a + (int64_t) b) >> 1;
    res = (int32_t) c;
    fwrite(&res, sizeof(int32_t), 1, output);
}