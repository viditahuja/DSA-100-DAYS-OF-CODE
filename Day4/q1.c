#include <stdio.h>

int main() {
    int n;
    int a[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int l = 0, r = n - 1;
    while (l < r) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}