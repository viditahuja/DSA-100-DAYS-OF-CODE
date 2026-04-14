#include <stdlib.h>

int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int* parent, int* rank, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py) return;

    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else if (rank[px] > rank[py]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));
    int* rank = (int*)calloc(edgesSize + 1, sizeof(int));

    for (int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(parent, u) == find(parent, v)) {
            result[0] = u;
            result[1] = v;
        } else {
            unionSet(parent, rank, u, v);
        }
    }

    *returnSize = 2;
    return result;
}