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

void mergeIntervals(Interval intervals[], int n)
{
    qsort(intervals, n, sizeof(Interval), compare);

    Interval result[n];
    int index = 0;

    result[0] = intervals[0];

    for (int i = 1; i < n; i++)
    {
        if (intervals[i].start <= result[index].end)
        {
            if (intervals[i].end > result[index].end)
            {
                result[index].end = intervals[i].end;
            }
        }
        else
        {
            index++;
            result[index] = intervals[i];
        }
    }

    printf("Merged Intervals:\n");

    for (int i = 0; i <= index; i++)
    {
        printf("[%d,%d] ", result[i].start, result[i].end);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    Interval intervals[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    return 0;
}