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
    if (n == 0) return NULL;

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

int isComplete(TreeNode* root) {
    TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int flag = 0;

    while (front < rear) {
        TreeNode* curr = queue[front++];

        if (!curr) {
            flag = 1;
        } else {
            if (flag) return 0;
            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }

    return 1;
}

int isMinHeap(TreeNode* root) {
    if (!root) return 1;

    if (root->left) {
        if (root->val > root->left->val) return 0;
    }

    if (root->right) {
        if (root->val > root->right->val) return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    TreeNode* root = buildTree(arr, n);

    if (isComplete(root) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}