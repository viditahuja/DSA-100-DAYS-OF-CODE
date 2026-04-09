#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findOrder(char dict[][100], int N, int K) {
    int adj[K][K];
    int indegree[K];

    for (int i = 0; i < K; i++) {
        indegree[i] = 0;
        for (int j = 0; j < K; j++)
            adj[i][j] = 0;
    }

    for (int i = 0; i < N - 1; i++) {
        char* w1 = dict[i];
        char* w2 = dict[i + 1];

        int j = 0;
        while (w1[j] && w2[j] && w1[j] == w2[j])
            j++;

        if (w1[j] && w2[j]) {
            int u = w1[j] - 'a';
            int v = w2[j] - 'a';

            if (!adj[u][v]) {
                adj[u][v] = 1;
                indegree[v]++;
            }
        }
    }

    int queue[K];
    int front = 0, rear = 0;

    for (int i = 0; i < K; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    char* result = (char*)malloc((K + 1) * sizeof(char));
    int idx = 0;

    while (front < rear) {
        int u = queue[front++];
        result[idx++] = u + 'a';

        for (int v = 0; v < K; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    result[idx] = '\0';
    return result;
}