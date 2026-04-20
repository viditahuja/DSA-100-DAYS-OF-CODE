#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, w;
} Edge;

Edge adj[MAX][MAX];
int deg[MAX];

int dist[MAX], visited[MAX];

int minDistance(int n) {
    int min = INT_MAX, idx = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) deg[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][deg[u]].v = v;
        adj[u][deg[u]].w = w;
        deg[u]++;

        adj[v][deg[v]].v = u;
        adj[v][deg[v]].w = w;
        deg[v]++;
    }

    int source;
    scanf("%d", &source);

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(n);
        if (u == -1) break;

        visited[u] = 1;

        for (int j = 0; j < deg[u]; j++) {
            int v = adj[u][j].v;
            int w = adj[u][j].w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}