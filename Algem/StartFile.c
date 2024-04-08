

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "iso646.h"
#include "func.h"

typedef struct versh{
    int dist;
    struct versh *out_contacts[200010];
    int cnt;
} versh;

int main() {
    int num_of_dug, num_of_versh, in, out;
    scanf("%d %d", &num_of_versh, &num_of_dug);
    versh *graph = (versh *) malloc(sizeof(versh) * (num_of_versh + 1));

    for (int i = 1; i < num_of_versh+1; ++i) {
        graph[i].cnt = 0;
        graph[i].dist = 10000000;
    }

    graph[1].dist = 0;
    for (int i = 0; i < num_of_dug; ++i) {
        scanf("%d %d", &out, &in);
        graph[out].out_contacts[graph[out].cnt++] = &graph[in];
    }
    for (int i = 1; i < num_of_versh+1; ++i) {
        for (int j = 0; j < graph[i].cnt; ++j) {
            if (graph[i].out_contacts[j]->dist> graph[i].dist+1)
            graph[i].out_contacts[j]->dist= graph[i].dist+1;
        }
    }
    for (int i = 1; i < num_of_versh+1; ++i) {
        if(graph[i].dist == 10000000){
            printf("-1\n");
        }
        else{
            printf("%d\n", graph[i].dist);
        }
    }
}
