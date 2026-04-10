#include <limits.h>
#include <stdlib.h>

typedef struct {
    int v, dist;
} Pair;

typedef struct {
    Pair heap[10000];
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

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* adjSize = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i <= n; i++)
        adj[i] = (int*)malloc(2 * timesSize * sizeof(int));

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        adj[u][adjSize[u]++] = v;
        adj[u][adjSize[u]++] = w;
    }

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[k] = 0;
    push(&h, k, 0);

    while (h.size > 0) {
        Pair p = pop(&h);
        int node = p.v;

        for (int i = 0; i < adjSize[node]; i += 2) {
            int neigh = adj[node][i];
            int wt = adj[node][i + 1];

            if (dist[node] + wt < dist[neigh]) {
                dist[neigh] = dist[node] + wt;
                push(&h, neigh, dist[neigh]);
            }
        }
    }

    int maxTime = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}