struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex, int* map) {
    if (inStart > inEnd) return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int inIndex = map[rootVal];

    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex, map);
    root->left = build(inorder, postorder, inStart, inIndex - 1, postIndex, map);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int* map = (int*)malloc(10001 * sizeof(int));

    for (int i = 0; i < inorderSize; i++)
        map[inorder[i]] = i;

    int postIndex = postorderSize - 1;

    return build(inorder, postorder, 0, inorderSize - 1, &postIndex, map);
}