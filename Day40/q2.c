#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* res = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    
    int top = -1;

    for(int i = 0; i < temperaturesSize; i++) {
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            res[idx] = i - idx;
        }
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    return res;
}