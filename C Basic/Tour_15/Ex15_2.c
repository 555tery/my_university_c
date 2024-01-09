//
// Created by Egor Kapov on 09.01.2024.
//
# include <stdio.h>
# include <stdlib.h>

int normirov(int delitel, int s) {
    if (s < 0) return delitel + s;
    else return s % delitel;
}

int main() {
    int num, delitel, **N, now;
    scanf("%d %d", &num, &delitel);
    N = (int **) malloc((num + 1) * sizeof(int *));
    N[0] = (int *) calloc(delitel, sizeof(int));
    N[0][0] = 1;
    for (int i = 1; i <= num; i++) {
        N[i] = (int *) calloc(delitel, sizeof(int));
        scanf("%d", &now);
        now = normirov(delitel, now % delitel);
        for (int j = 0; j < delitel; j++) {
            if (N[i - 1][j]) {
                N[i][normirov(delitel, j + now)] = 1;
                N[i][normirov(delitel, j - now)] = 1;
            }
        }
    }
    if (N[num][0]) printf("Divisible");
    else printf("Not divisible");
    free(N);
    return 0;
}