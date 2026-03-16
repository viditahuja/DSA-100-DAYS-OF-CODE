int size = 0;

void dfs(struct TreeNode* root, int* res) {
    if(root == NULL) return;
    res[size++] = root->val;
    dfs(root->left, res);
    dfs(root->right, res);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 10000);
    size = 0;
    dfs(root, res);
    *returnSize = size;
    return res;
}