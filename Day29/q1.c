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

int length(struct node* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

struct node* rotate(struct node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    int len = length(head);
    k = k % len;
    if(k == 0)
        return head;

    struct node *temp = head, *tail = head;

    while(tail->next)
        tail = tail->next;

    tail->next = head;

    int steps = len - k;
    while(steps--)
        tail = tail->next;

    head = tail->next;
    tail->next = NULL;

    return head;
}

void print(struct node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct node* head = create(n);

    scanf("%d", &k);

    head = rotate(head, k);

    print(head);

    return 0;
}