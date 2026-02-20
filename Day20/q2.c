int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int** res = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));
    int k = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1, r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0) {
                res[k] = (int*)malloc(3 * sizeof(int));
                res[k][0] = nums[i];
                res[k][1] = nums[l];
                res[k][2] = nums[r];
                (*returnColumnSizes)[k] = 3;
                k++;

                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;

                l++;
                r--;
            }
            else if (sum < 0)
                l++;
            else
                r--;
        }
    }

    *returnSize = k;
    return res;
}