#include <stdlib.h>

void dfs(int u, int parent, int** adj, int* adjSize, int* disc, int* low, int* time,
         int** result, int* returnSize) {

    disc[u] = low[u] = (*time)++;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, adj, adjSize, disc, low, time, result, returnSize);

            if (low[v] > disc[u]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }

            if (low[v] < low[u])
                low[u] = low[v];

        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize, int* returnSize,
                          int** returnColumnSizes) {

    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        adj[i] = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        disc[i] = -1;

    int time = 0;

    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnSize = 0;

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1)
            dfs(i, -1, adj, adjSize, disc, low, &time, result, returnSize);
    }

    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;

    return result;
}