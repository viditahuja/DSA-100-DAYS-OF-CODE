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

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}