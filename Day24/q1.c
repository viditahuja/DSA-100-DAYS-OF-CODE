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

struct node* deleteKey(struct node* head, int key) {
    struct node *temp = head, *prev = NULL;

    while(temp) {
        if(temp->data == key) {
            if(prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
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
    int n, key;
    scanf("%d", &n);

    struct node* head = create(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    print(head);

    return 0;
}