#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void relativeSortArray(int arr1[], int n1, int arr2[], int n2)
{
    int freq[1001] = {0};
    int i, j, index = 0;

    for(i = 0; i < n1; i++)
    {
        freq[arr1[i]]++;
    }

    for(i = 0; i < n2; i++)
    {
        while(freq[arr2[i]] > 0)
        {
            arr1[index++] = arr2[i];
            freq[arr2[i]]--;
        }
    }

    int temp[1000], k = 0;

    for(i = 0; i <= 1000; i++)
    {
        while(freq[i] > 0)
        {
            temp[k++] = i;
            freq[i]--;
        }
    }

    qsort(temp, k, sizeof(int), compare);

    for(i = 0; i < k; i++)
    {
        arr1[index++] = temp[i];
    }
}

int main()
{
    int n1, n2, i;

    scanf("%d", &n1);

    int arr1[n1];

    for(i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);

    int arr2[n2];

    for(i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    relativeSortArray(arr1, n1, arr2, n2);

    for(i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }

    return 0;
}