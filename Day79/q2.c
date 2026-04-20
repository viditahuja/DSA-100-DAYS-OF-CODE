#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], rev[MAX][MAX];
int deg[MAX], rdeg[MAX];
int visited[MAX], stack[MAX];
int top = -1;

void dfs1(int u) {
    visited[u] = 1;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs1(v);
    }
    stack[++top] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    for (int i = 0; i < rdeg[u]; i++) {
        int v = rev[u][i];
        if (!visited[v]) dfs2(v);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        deg[i] = rdeg[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][deg[u]++] = v;
        rev[v][rdeg[v]++] = u;
    }

    for (int i = 0; i < V; i++) visited[i] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs1(i);
    }

    for (int i = 0; i < V; i++) visited[i] = 0;

    int scc = 0;

    while (top != -1) {
        int u = stack[top--];
        if (!visited[u]) {
            dfs2(u);
            scc++;
        }
    }

    printf("%d\n", scc);

    return 0;
}