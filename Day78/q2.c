#include <stdio.h>

#define MAX 100

int V;
int time = 0;

void dfs(int u, int adj[MAX][MAX], int visited[], int disc[], int low[], int parent[], int ap[]) {
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (int v = 0; v < V; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v, adj, visited, disc, low, parent, ap);

                if (low[v] < low[u])
                    low[u] = low[v];

                if (parent[u] == -1 && children > 1)
                    ap[u] = 1;

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            }
            else if (v != parent[u]) {
                if (disc[v] < low[u])
                    low[u] = disc[v];
            }
        }
    }
}

void articulationPoints(int adj[MAX][MAX]) {
    int visited[MAX], disc[MAX], low[MAX], parent[MAX], ap[MAX];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        parent[i] = -1;
        ap[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, adj, visited, disc, low, parent, ap);
    }

    for (int i = 0; i < V; i++) {
        if (ap[i])
            printf("%d ", i);
    }
}

int main() {
    int adj[MAX][MAX];

    scanf("%d", &V);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &adj[i][j]);

    articulationPoints(adj);

    return 0;
}