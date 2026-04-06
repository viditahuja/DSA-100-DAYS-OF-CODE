int dfs(int v, int parent, int* visited, int** adj, int* adjSize) {
    visited[v] = 1;

    for (int i = 0; i < adjSize[v]; i++) {
        int u = adj[v][i];

        if (!visited[u]) {
            if (dfs(u, v, visited, adj, adjSize))
                return 1;
        } else if (u != parent) {
            return 1;
        }
    }

    return 0;
}

int hasCycle(int V, int** edges, int edgesSize, int* edgesColSize) {
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        adj[i] = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* visited = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, adjSize))
                return 1;
        }
    }

    return 0;
}