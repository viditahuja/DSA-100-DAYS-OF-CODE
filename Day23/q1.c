#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
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

struct node* merge(struct node* a, struct node* b) {
    struct node *head = NULL, *temp = NULL, *newnode;

    while(a && b) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;

        if(a->data < b->data) {
            newnode->data = a->data;
            a = a->next;
        } else {
            newnode->data = b->data;
            b = b->next;
        }

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    while(a) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = a->data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        a = a->next;
    }

    while(b) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = b->data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        b = b->next;
    }

    return head;
}

void print(struct node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct node* list1 = create(n);

    scanf("%d", &m);
    struct node* list2 = create(m);

    struct node* result = merge(list1, list2);
    print(result);

    return 0;
}