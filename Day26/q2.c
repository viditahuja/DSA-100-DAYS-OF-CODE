typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (obj->head == NULL) {
        obj->head = node;
    } else {
        Node* curr = obj->head;
        while (curr->next)
            curr = curr->next;
        curr->next = node;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;

    Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++)
        curr = curr->next;

    node->next = curr->next;
    curr->next = node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;

    Node* temp;

    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}