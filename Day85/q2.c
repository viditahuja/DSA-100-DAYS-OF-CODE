#include <stdio.h>

int findMin(int nums[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }

    return nums[low];
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[5000];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("%d", findMin(nums, n));

    return 0;
}