#include <stdio.h>
#include <string.h>

int heap[100000];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while(i > 0) {
        int p = (i - 1) / 2;
        if(heap[p] > heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(int i) {
    while(2*i + 1 < size) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int s = l;

        if(r < size && heap[r] < heap[l]) s = r;

        if(heap[i] > heap[s]) {
            swap(&heap[i], &heap[s]);
            i = s;
        } else break;
    }
}

void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin() {
    if(size == 0) return -1;
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return min;
}

int peek() {
    if(size == 0) return -1;
    return heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } 
        else if(strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } 
        else if(strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}