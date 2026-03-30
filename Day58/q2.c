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

TreeNode* build(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex, int map[]) {
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    TreeNode* root = newNode(rootVal);

    int inIndex = map[rootVal];

    root->left = build(preorder, inorder, inStart, inIndex - 1, preIndex, map);
    root->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex, map);

    return root;
}

void postorder(TreeNode* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int map[10000];

    for (int i = 0; i < n; i++)
        map[inorder[i]] = i;

    int preIndex = 0;

    TreeNode* root = build(preorder, inorder, 0, n - 1, &preIndex, map);

    postorder(root);

    return 0;
}