#include <stdlib.h>

typedef struct {
    int val;
    int freq;
} Node;

void swap(Node* a, Node* b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(Node* heap, int i) {
    while(i > 0) {
        int p = (i - 1) / 2;
        if(heap[p].freq > heap[i].freq) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(Node* heap, int size, int i) {
    while(2*i + 1 < size) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int s = l;

        if(r < size && heap[r].freq < heap[l].freq) s = r;

        if(heap[i].freq > heap[s].freq) {
            swap(&heap[i], &heap[s]);
            i = s;
        } else break;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int* freq = (int*)calloc(20001, sizeof(int));
    
    for(int i = 0; i < numsSize; i++) {
        freq[nums[i] + 10000]++;
    }

    Node* heap = (Node*)malloc(sizeof(Node) * k);
    int size = 0;

    for(int i = 0; i < 20001; i++) {
        if(freq[i] > 0) {
            Node node = {i - 10000, freq[i]};

            if(size < k) {
                heap[size] = node;
                heapifyUp(heap, size);
                size++;
            } else if(node.freq > heap[0].freq) {
                heap[0] = node;
                heapifyDown(heap, size, 0);
            }
        }
    }

    int* res = (int*)malloc(sizeof(int) * k);
    for(int i = 0; i < k; i++) {
        res[i] = heap[i].val;
    }

    *returnSize = k;
    return res;
}