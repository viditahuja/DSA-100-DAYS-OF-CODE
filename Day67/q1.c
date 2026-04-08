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

void dfs(Node* adj[], int visited[], int stack[], int* top, int v) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(adj, visited, stack, top, temp->data);
        }
        temp = temp->next;
    }

    stack[(*top)++] = v;
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
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[n];
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, stack, &top, i);
        }
    }

    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}