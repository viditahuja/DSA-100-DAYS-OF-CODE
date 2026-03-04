#include <stdio.h>

int stack[1000];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if(top >= 0)
        top--;
}

void display() {
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
        pop();

    display();

    return 0;
}