#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[])
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pair *L = (Pair *)malloc(n1 * sizeof(Pair));
    Pair *R = (Pair *)malloc(n2 * sizeof(Pair));

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2)
    {
        if (L[i].value <= R[j].value)
        {
            count[L[i].index] += rightCount;
            arr[k++] = L[i++];
        }
        else
        {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        count[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Pair arr[], int left, int right, int count[])
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);

        merge(arr, left, mid, right, count);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    int nums[n];
    Pair arr[n];
    int count[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);

        arr[i].value = nums[i];
        arr[i].index = i;

        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }

    return 0;
}