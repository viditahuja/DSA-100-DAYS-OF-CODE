#include <stdio.h>

int main() {
    int n, k;
    int a[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    k = k % n;

    for (int i = n - k; i < n; i++)
        printf("%d ", a[i]);

    for (int i = 0; i < n - k; i++)
        printf("%d ", a[i]);

    return 0;
}