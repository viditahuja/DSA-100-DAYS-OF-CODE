int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int curr = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (curr < 0)
            curr = nums[i];
        else
            curr += nums[i];

        if (curr > maxSum)
            maxSum = curr;
    }

    return maxSum;
}