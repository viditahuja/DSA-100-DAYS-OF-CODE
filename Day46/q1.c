#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void levelOrder(Node* root) {
    if(root == NULL) return;

    Node* queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->data);

        if(curr->left) queue[rear++] = curr->left;
        if(curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(n == 0 || arr[0] == -1) return 0;

    Node* root = newNode(arr[0]);

    Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < n) {
        Node* curr = queue[front++];

        if(i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    levelOrder(root);

    return 0;
}