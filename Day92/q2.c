#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if(low <= high)
    {
        int pi = partition(arr, low, high);

        if(pi == k)
            return arr[pi];
        else if(pi > k)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1;
}

int findKthLargest(int arr[], int n, int k)
{
    return quickSelect(arr, 0, n - 1, n - k);
}

int main()
{
    int nums[] = {3,2,1,5,6,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 2;

    printf("%d", findKthLargest(nums, n, k));

    return 0;
}