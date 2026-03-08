#include <stdio.h>

int q[1000];
int front = 0, rear = -1, size = 0, cap = 1000;

void enqueue(int x) {
    rear = (rear + 1) % cap;
    q[rear] = x;
    size++;
}

void dequeue() {
    if(size > 0) {
        front = (front + 1) % cap;
        size--;
    }
}

void display() {
    int i = front;
    for(int count = 0; count < size; count++) {
        printf("%d ", q[i]);
        i = (i + 1) % cap;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
        dequeue();

    display();

    return 0;
}