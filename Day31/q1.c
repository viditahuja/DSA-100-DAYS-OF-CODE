#include <stdio.h>

int stack[1000];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else
        printf("%d\n", stack[top--]);
}

void display() {
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int n, type, val;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &type);

        if(type == 1) {
            scanf("%d", &val);
            push(val);
        } 
        else if(type == 2) {
            pop();
        } 
        else if(type == 3) {
            display();
        }
    }

    return 0;
}