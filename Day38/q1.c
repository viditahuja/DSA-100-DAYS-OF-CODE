#include <stdio.h>

int dq[1000];
int front = -1, rear = -1, size = 0;

void push_front(int x) {
    if(size == 1000) return;

    if(size == 0) {
        front = rear = 0;
    } else {
        front = (front - 1 + 1000) % 1000;
    }
    dq[front] = x;
    size++;
}

void push_back(int x) {
    if(size == 1000) return;

    if(size == 0) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % 1000;
    }
    dq[rear] = x;
    size++;
}

void pop_front() {
    if(size == 0) return;

    if(size == 1) {
        front = rear = -1;
    } else {
        front = (front + 1) % 1000;
    }
    size--;
}

void pop_back() {
    if(size == 0) return;

    if(size == 1) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + 1000) % 1000;
    }
    size--;
}

int get_front() {
    if(size == 0) return -1;
    return dq[front];
}

int get_back() {
    if(size == 0) return -1;
    return dq[rear];
}

int is_empty() {
    return size == 0;
}

int get_size() {
    return size;
}

void display() {
    int i = front;
    for(int count = 0; count < size; count++) {
        printf("%d ", dq[i]);
        i = (i + 1) % 1000;
    }
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    while(n--) {
        scanf("%s", op);

        if(op[0]=='p' && op[5]=='f') {
            scanf("%d", &x);
            push_front(x);
        }
        else if(op[0]=='p' && op[5]=='b') {
            scanf("%d", &x);
            push_back(x);
        }
        else if(op[0]=='p' && op[4]=='f') {
            pop_front();
        }
        else if(op[0]=='p' && op[4]=='b') {
            pop_back();
        }
        else if(op[0]=='f') {
            printf("%d\n", get_front());
        }
        else if(op[0]=='b') {
            printf("%d\n", get_back());
        }
        else if(op[0]=='e') {
            printf("%d\n", is_empty());
        }
        else if(op[0]=='s') {
            printf("%d\n", get_size());
        }
    }

    display();

    return 0;
}