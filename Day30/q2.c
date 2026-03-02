struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* temp = &dummy;

    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        temp->next = node;
        temp = node;
    }

    return reverse(dummy.next);
}