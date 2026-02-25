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

int countKey(struct node* head, int key) {
    int count = 0;
    while(head) {
        if(head->data == key)
            count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, key;
    scanf("%d", &n);

    struct node* head = create(n);

    scanf("%d", &key);

    printf("%d", countKey(head, key));

    return 0;
}