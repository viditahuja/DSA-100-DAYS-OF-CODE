#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Pair {
    Node* node;
    int hd;
} Pair;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void verticalOrder(Node* root) {
    if (!root) return;

    Pair queue[1000];
    int front = 0, rear = 0;

    int map[2000][100];
    int count[2000] = {0};

    int offset = 1000;

    queue[rear++] = (Pair){root, 0};

    while (front < rear) {
        Pair p = queue[front++];
        Node* node = p.node;
        int hd = p.hd + offset;

        map[hd][count[hd]++] = node->data;

        if (node->left)
            queue[rear++] = (Pair){node->left, p.hd - 1};

        if (node->right)
            queue[rear++] = (Pair){node->right, p.hd + 1};
    }

    for (int i = 0; i < 2000; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}