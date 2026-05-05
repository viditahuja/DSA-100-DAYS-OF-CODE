#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    float data;
    struct Node *next;
} Node;

void insertSorted(Node **head, float value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *temp = *head;

        while (temp->next != NULL && temp->next->data < value)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void bucketSort(float arr[], int n)
{
    Node *buckets[n];

    for (int i = 0; i < n; i++)
    {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i];
        insertSorted(&buckets[index], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        Node *temp = buckets[i];

        while (temp != NULL)
        {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }

    return 0;
}