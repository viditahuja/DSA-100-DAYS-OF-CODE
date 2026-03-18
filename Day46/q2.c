int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;

    while(front < rear) {
        int size = rear - front;

        result[level] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[level] = size;

        for(int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            result[level][i] = node->val;

            if(node->left) queue[rear++] = node->left;
            if(node->right) queue[rear++] = node->right;
        }

        level++;
    }

    *returnSize = level;
    return result;
}