#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

int dfs(Node* adj[], int visited[], int v, int parent) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        int u = temp->data;

        if (!visited[u]) {
            if (dfs(adj, visited, u, v))
                return 1;
        } else if (u != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, visited, i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}