#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int left, int mid, int right)
{
    int count = 0;
    int j = mid + 1;

    for (int i = left; i <= mid; i++)
    {
        while (j <= right && (long long)arr[i] > 2LL * arr[j])
        {
            j++;
        }

        count += (j - (mid + 1));
    }

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, k = left;
    j = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);

    return count;
}

int mergeSort(int arr[], int left, int right)
{
    int count = 0;

    if (left < right)
    {
        int mid = (left + right) / 2;

        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);

        count += merge(arr, left, mid, right);
    }

    return count;
}

int main()
{
    int n;

    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d", mergeSort(nums, 0, n - 1));

    free(nums);

    return 0;
}