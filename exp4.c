#include <stdio.h>
#define SIZE 5

int q1[SIZE], q2[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue(int q[], int *rear, int x) {
    q[++(*rear)] = x;
}

int dequeue(int q[], int *front) {
    return q[(*front)++];
}

int isEmpty(int front, int rear) {
    return (front == -1 || front > rear);
}

void push(int x) {
    enqueue(q2, &rear2, x);
    if (front2 == -1) front2 = 0;

    while (!isEmpty(front1, rear1)) {
        enqueue(q2, &rear2, dequeue(q1, &front1));
    }

    // swap q1 and q2
    front1 = 0;
    rear1 = rear2;

    front2 = rear2 = -1;
}

void pop() {
    if (isEmpty(front1, rear1))
        printf("Stack Empty\n");
    else
        printf("%d popped\n", dequeue(q1, &front1));
}

void display() {
    for (int i = front1; i <= rear1; i++)
        printf("%d ", q1[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    pop();
    display();
    return 0;
}