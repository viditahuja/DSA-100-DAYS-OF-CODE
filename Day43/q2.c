int size = 0;

void dfs(struct TreeNode* root, int* res) {
    if(root == NULL) return;
    dfs(root->left, res);
    res[size++] = root->val;
    dfs(root->right, res);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 10000);
    size = 0;
    dfs(root, res);
    *returnSize = size;
    return res;
}