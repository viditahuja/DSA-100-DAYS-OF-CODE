void dfs(int** image, int imageSize, int* imageColSize, int r, int c, int oldColor, int newColor) {
    if (r < 0 || c < 0 || r >= imageSize || c >= imageColSize[0]) return;
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(image, imageSize, imageColSize, r + 1, c, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r - 1, c, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r, c + 1, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r, c - 1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int oldColor = image[sr][sc];

    if (oldColor != color)
        dfs(image, imageSize, imageColSize, sr, sc, oldColor, color);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}