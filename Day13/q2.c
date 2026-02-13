int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int* res = (int*)malloc(rows * cols * sizeof(int));
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++)
            res[k++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            res[k++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                res[k++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                res[k++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = k;
    return res;
}