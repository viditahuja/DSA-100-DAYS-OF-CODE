#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

struct Node* LCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (p < root->data && q < root->data)
        return LCA(root->left, p, q);

    if (p > root->data && q > root->data)
        return LCA(root->right, p, q);

    return root;
}

int main() {
    int n, x, p, q;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &p, &q);

    struct Node* ans = LCA(root, p, q);

    if (ans != NULL)
        printf("%d\n", ans->data);

    return 0;
}