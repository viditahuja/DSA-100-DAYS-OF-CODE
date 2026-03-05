#include <stdio.h>
#include <ctype.h>

char stack[1000];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char x) {
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    if(x == '^') return 3;
    return 0;
}

int main() {
    char exp[1000], result[1000];
    int k = 0;

    scanf("%s", exp);

    for(int i = 0; exp[i]; i++) {
        char c = exp[i];

        if(isalnum(c)) {
            result[k++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(top != -1 && peek() != '(')
                result[k++] = pop();
            pop();
        }
        else {
            while(top != -1 && precedence(peek()) >= precedence(c))
                result[k++] = pop();
            push(c);
        }
    }

    while(top != -1)
        result[k++] = pop();

    result[k] = '\0';

    printf("%s", result);

    return 0;
}