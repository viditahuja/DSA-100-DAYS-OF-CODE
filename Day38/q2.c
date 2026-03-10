int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *res = (int*)malloc(sizeof(int) * numsSize);
    int *dq = (int*)malloc(sizeof(int) * numsSize);
    
    int front = 0, rear = -1;
    int idx = 0;

    for(int i = 0; i < numsSize; i++) {
        if(front <= rear && dq[front] <= i - k) front++;

        while(front <= rear && nums[dq[rear]] < nums[i]) rear--;

        dq[++rear] = i;

        if(i >= k - 1) {
            res[idx++] = nums[dq[front]];
        }
    }

    *returnSize = idx;
    return res;
}