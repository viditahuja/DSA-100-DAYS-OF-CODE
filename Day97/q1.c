#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Meeting;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index)
{
    while (1)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

void insertHeap(int heap[], int *size, int value)
{
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int removeMin(int heap[], int *size)
{
    int min = heap[0];

    heap[0] = heap[*size - 1];
    (*size)--;

    heapifyDown(heap, *size, 0);

    return min;
}

int compare(const void *a, const void *b)
{
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    return m1->start - m2->start;
}

int minMeetingRooms(Meeting meetings[], int n)
{
    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    insertHeap(heap, &heapSize, meetings[0].end);

    int maxRooms = 1;

    for (int i = 1; i < n; i++)
    {
        if (meetings[i].start >= heap[0])
        {
            removeMin(heap, &heapSize);
        }

        insertHeap(heap, &heapSize, meetings[i].end);

        if (heapSize > maxRooms)
        {
            maxRooms = heapSize;
        }
    }

    return maxRooms;
}

int main()
{
    int n;

    scanf("%d", &n);

    Meeting meetings[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    printf("%d", minMeetingRooms(meetings, n));

    return 0;
}