#include <stdio.h>

int main() {
    int n;
    int a[100];
    int count = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == 0)
                count++;
        }
    }

    printf("%d", count);

    return 0;
}