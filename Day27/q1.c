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

int main() {
    int n, m;
    scanf("%d", &n);
    struct node* head1 = create(n);

    scanf("%d", &m);
    struct node* head2 = create(m);

    int len1 = length(head1);
    int len2 = length(head2);

    struct node *p1 = head1, *p2 = head2;

    if(len1 > len2) {
        for(int i = 0; i < len1 - len2; i++)
            p1 = p1->next;
    } else {
        for(int i = 0; i < len2 - len1; i++)
            p2 = p2->next;
    }

    while(p1 && p2) {
        if(p1->data == p2->data) {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}