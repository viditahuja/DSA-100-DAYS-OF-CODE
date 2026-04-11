#include <limits.h>
#include <stdlib.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        int* temp = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < temp[v])
                temp[v] = dist[u] + w;
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    if (dist[dst] == INT_MAX)
        return -1;

    return dist[dst];
}