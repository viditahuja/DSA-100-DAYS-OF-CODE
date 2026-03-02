#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node* next;
};

struct node* create(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d %d", &newnode->coef, &newnode->exp);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}

void print(struct node* head) {
    while(head) {
        if(head->exp == 0)
            printf("%d", head->coef);
        else if(head->exp == 1)
            printf("%dx", head->coef);
        else
            printf("%dx^%d", head->coef, head->exp);

        if(head->next)
            printf(" + ");

        head = head->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct node* head = create(n);

    print(head);

    return 0;
}