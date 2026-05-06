#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b)
{
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    return i1->start - i2->start;
}

void mergeIntervals(Interval arr[], int n)
{
    qsort(arr, n, sizeof(Interval), compare);

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[index].end >= arr[i].start)
        {
            if (arr[i].end > arr[index].end)
            {
                arr[index].end = arr[i].end;
            }
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }

    for (int i = 0; i <= index; i++)
    {
        printf("%d %d\n", arr[i].start, arr[i].end);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}