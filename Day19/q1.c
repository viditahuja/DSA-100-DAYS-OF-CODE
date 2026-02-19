#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    int a[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    int l = 0, r = n - 1;
    int minSum = a[l] + a[r];
    int x = a[l], y = a[r];

    while (l < r) {
        int sum = a[l] + a[r];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            x = a[l];
            y = a[r];
        }

        if (sum < 0)
            l++;
        else
            r--;
    }

    printf("%d %d", x, y);

    return 0;
}