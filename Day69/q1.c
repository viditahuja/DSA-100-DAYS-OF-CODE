#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int v, weight;
    struct Node* next;
} Node;

Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    int v, dist;
} Pair;

typedef struct {
    Pair heap[1000];
    int size;
} MinHeap;

void swap(Pair* a, Pair* b) {
    Pair t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap* h, int i) {
    while (i > 0 && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if (r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap* h, int v, int dist) {
    h->heap[h->size] = (Pair){v, dist};
    heapifyUp(h, h->size);
    h->size++;
}

Pair pop(MinHeap* h) {
    Pair root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapifyDown(h, 0);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u, w);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int src;
    scanf("%d", &src);

    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (h.size > 0) {
        Pair p = pop(&h);
        int node = p.v;

        Node* temp = adj[node];
        while (temp) {
            int neigh = temp->v;
            int wt = temp->weight;

            if (dist[node] + wt < dist[neigh]) {
                dist[neigh] = dist[node] + wt;
                push(&h, neigh, dist[neigh]);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}