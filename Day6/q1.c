#include <stdio.h>

int main() {
    int n;
    int a[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n > 0)
        printf("%d ", a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            printf("%d ", a[i]);
    }

    return 0;
}