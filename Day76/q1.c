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

void dfs(Node* adj[], int visited[], int v) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(adj, visited, temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n + 1];
    for (int i = 1; i <= n; i++)
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

    int visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}