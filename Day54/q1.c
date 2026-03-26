#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    int front = 0, rear = 0;

    TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        TreeNode* curr = queue[front++];

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

void zigzagTraversal(TreeNode* root) {
    if (!root) return;

    TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int temp[1000];

        for (int i = 0; i < size; i++) {
            TreeNode* curr = queue[front++];
            temp[i] = curr->val;

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }

        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", temp[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", temp[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    TreeNode* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}