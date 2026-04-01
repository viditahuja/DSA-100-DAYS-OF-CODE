int dfs(struct TreeNode* root, int* cameras) {
    if (!root) return 1;

    int left = dfs(root->left, cameras);
    int right = dfs(root->right, cameras);

    if (left == 2 || right == 2) {
        (*cameras)++;
        return 0;
    }

    if (left == 0 || right == 0) {
        return 1;
    }

    return 2;
}

int minCameraCover(struct TreeNode* root) {
    int cameras = 0;

    if (dfs(root, &cameras) == 2)
        cameras++;

    return cameras;
}