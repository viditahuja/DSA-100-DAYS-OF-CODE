#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100];

    scanf("%d", &p);
    for (int i = 0; i < p; i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
        scanf("%d", &b[i]);

    int i = 0, j = 0;

    while (i < p && j < q) {
        if (a[i] <= b[j])
            printf("%d ", a[i++]);
        else
            printf("%d ", b[j++]);
    }

    while (i < p)
        printf("%d ", a[i++]);

    while (j < q)
        printf("%d ", b[j++]);

    return 0;
}