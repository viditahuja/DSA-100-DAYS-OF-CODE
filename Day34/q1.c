#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    struct node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main() {
    char exp[1000];
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");

    while(token) {
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))) {
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();

            if(token[0] == '+') push(a + b);
            else if(token[0] == '-') push(a - b);
            else if(token[0] == '*') push(a * b);
            else if(token[0] == '/') push(a / b);
        }
        token = strtok(NULL, " ");
    }

    printf("%d", pop());

    return 0;
}