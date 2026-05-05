#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct
{
    int min;
    int max;
    int used;
} Bucket;

int maximumGap(int nums[], int n)
{
    if (n < 2)
        return 0;

    int minVal = nums[0];
    int maxVal = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] < minVal)
            minVal = nums[i];

        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    if (minVal == maxVal)
        return 0;

    int bucketSize = fmax(1, (maxVal - minVal) / (n - 1));
    int bucketCount = ((maxVal - minVal) / bucketSize) + 1;

    Bucket *buckets = (Bucket *)malloc(bucketCount * sizeof(Bucket));

    for (int i = 0; i < bucketCount; i++)
    {
        buckets[i].used = 0;
        buckets[i].min = INT_MAX;
        buckets[i].max = INT_MIN;
    }

    for (int i = 0; i < n; i++)
    {
        int index = (nums[i] - minVal) / bucketSize;

        if (!buckets[index].used)
        {
            buckets[index].used = 1;
            buckets[index].min = nums[i];
            buckets[index].max = nums[i];
        }
        else
        {
            if (nums[i] < buckets[index].min)
                buckets[index].min = nums[i];

            if (nums[i] > buckets[index].max)
                buckets[index].max = nums[i];
        }
    }

    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++)
    {
        if (!buckets[i].used)
            continue;

        int gap = buckets[i].min - prevMax;

        if (gap > maxGap)
            maxGap = gap;

        prevMax = buckets[i].max;
    }

    free(buckets);

    return maxGap;
}

int main()
{
    int n;

    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d", maximumGap(nums, n));

    return 0;
}