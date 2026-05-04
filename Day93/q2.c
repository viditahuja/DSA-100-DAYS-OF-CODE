#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;

        struct ListNode* prev = &dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = next;
    }

    return dummy.next;
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, x;
    scanf("%d", &n);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct ListNode* node = createNode(x);
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    head = insertionSortList(head);
    printList(head);

    return 0;
}