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

void flatten(TreeNode* root) {
    TreeNode* curr = root;

    while (curr) {
        if (curr->left) {
            TreeNode* prev = curr->left;

            while (prev->right)
                prev = prev->right;

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

void printFlattened(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    TreeNode* root = buildTree(arr, n);

    flatten(root);

    printFlattened(root);

    return 0;
}