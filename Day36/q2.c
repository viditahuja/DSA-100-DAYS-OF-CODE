#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int cap;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    obj->cap = k;
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->size == obj->cap) return false;

    obj->front = (obj->front - 1 + obj->cap) % obj->cap;
    obj->arr[obj->front] = value;

    if(obj->size == 0)
        obj->rear = obj->front;

    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj->size == obj->cap) return false;

    obj->rear = (obj->rear + 1) % obj->cap;
    obj->arr[obj->rear] = value;

    if(obj->size == 0)
        obj->front = obj->rear;

    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj->size == 0) return false;

    obj->front = (obj->front + 1) % obj->cap;
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj->size == 0) return false;

    obj->rear = (obj->rear - 1 + obj->cap) % obj->cap;
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj->size == 0) return -1;
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj->size == 0) return -1;
    return obj->arr[obj->rear];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->cap;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}