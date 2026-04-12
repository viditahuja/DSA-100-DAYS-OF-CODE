#include <stdlib.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int* minDist = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        minDist[i] = 10000000;

    minDist[0] = 0;
    int cost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        visited[u] = 1;
        cost += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dx = points[u][0] - points[v][0];
                if (dx < 0) dx = -dx;
                int dy = points[u][1] - points[v][1];
                if (dy < 0) dy = -dy;
                int dist = dx + dy;

                if (dist < minDist[v])
                    minDist[v] = dist;
            }
        }
    }

    return cost;
}