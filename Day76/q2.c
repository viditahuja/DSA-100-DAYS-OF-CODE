#include <stdlib.h>

struct Node* dfs(struct Node* node, struct Node** map) {
    if (!node) return NULL;

    if (map[node->val] != NULL)
        return map[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->neighbors = (struct Node**)malloc(100 * sizeof(struct Node*));
    clone->numNeighbors = 0;

    map[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[clone->numNeighbors++] =
            dfs(node->neighbors[i], map);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* node) {
    if (!node) return NULL;

    struct Node** map = (struct Node**)calloc(101, sizeof(struct Node*));

    return dfs(node, map);
}