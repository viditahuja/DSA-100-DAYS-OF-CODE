#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int q[n], stack[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    int top = -1;

    for(int i = 0; i < n; i++)
        stack[++top] = q[i];

    for(int i = 0; i < n; i++)
        q[i] = stack[top--];

    for(int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}