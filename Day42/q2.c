#include <stdlib.h>

typedef struct {
    int *maxHeap;
    int *minHeap;
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int heap[], int i) {
    while(i > 0) {
        int p = (i - 1) / 2;
        if(heap[p] < heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void maxHeapifyDown(int heap[], int size, int i) {
    while(2*i + 1 < size) {
        int l = 2*i + 1, r = 2*i + 2, m = l;
        if(r < size && heap[r] > heap[l]) m = r;
        if(heap[i] < heap[m]) {
            swap(&heap[i], &heap[m]);
            i = m;
        } else break;
    }
}

void minHeapifyUp(int heap[], int i) {
    while(i > 0) {
        int p = (i - 1) / 2;
        if(heap[p] > heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void minHeapifyDown(int heap[], int size, int i) {
    while(2*i + 1 < size) {
        int l = 2*i + 1, r = 2*i + 2, m = l;
        if(r < size && heap[r] < heap[l]) m = r;
        if(heap[i] > heap[m]) {
            swap(&heap[i], &heap[m]);
            i = m;
        } else break;
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxHeap = (int*)malloc(sizeof(int) * 100000);
    obj->minHeap = (int*)malloc(sizeof(int) * 100000);
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if(obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        obj->maxHeap[obj->maxSize] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize);
        obj->maxSize++;
    } else {
        obj->minHeap[obj->minSize] = num;
        minHeapifyUp(obj->minHeap, obj->minSize);
        obj->minSize++;
    }

    if(obj->maxSize > obj->minSize + 1) {
        int val = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);

        obj->minHeap[obj->minSize] = val;
        minHeapifyUp(obj->minHeap, obj->minSize);
        obj->minSize++;
    } else if(obj->minSize > obj->maxSize) {
        int val = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);

        obj->maxHeap[obj->maxSize] = val;
        maxHeapifyUp(obj->maxHeap, obj->maxSize);
        obj->maxSize++;
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if(obj->maxSize > obj->minSize)
        return obj->maxHeap[0];
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}