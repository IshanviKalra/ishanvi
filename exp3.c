#include <stdio.h>
#define SIZE 5

int cq[SIZE], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % SIZE == front)
        printf("Queue Full\n");
    else {
        if (front == -1) front = rear = 0;
        else rear = (rear + 1) % SIZE;
        cq[rear] = x;
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue Empty\n");
    else if (front == rear) {
        printf("%d deleted\n", cq[front]);
        front = rear = -1;
    } else {
        printf("%d deleted\n", cq[front]);
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    return 0;
}