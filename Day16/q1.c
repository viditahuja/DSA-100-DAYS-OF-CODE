#include <stdio.h>

int main() {
    int n;
    int a[100];
    int visited[100] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}