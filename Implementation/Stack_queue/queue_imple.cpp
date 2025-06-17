#define SIZE 100
int queue[SIZE];
int front = -1, rear = -1;
#include <stdio.h>

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue[front];
    front++;
    return value;
}
