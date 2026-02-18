#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == SIZE - 1)
        printf("Queue is Full\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = x;
        printf("%d inserted\n", x);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
        printf("%d deleted\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear)
        printf("Empty\n");
    else {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    display();
    return 0;
}