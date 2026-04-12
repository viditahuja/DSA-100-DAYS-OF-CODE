#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
}

int search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == key)
            return 1;

        if (table[idx] == -1)
            return 0;
    }

    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init();

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key, m);
        } else {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}