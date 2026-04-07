int dfs(int v, int** adj, int* adjSize, int* visited, int* recStack) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < adjSize[v]; i++) {
        int u = adj[v][i];

        if (!visited[u]) {
            if (dfs(u, adj, adjSize, visited, recStack))
                return 1;
        } else if (recStack[u]) {
            return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++)
        adj[i] = (int*)malloc(numCourses * sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack))
                return false;
        }
    }

    return true;
}