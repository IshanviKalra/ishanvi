/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes 
elements from front. Display remaining elements in correct order.*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if((rear + 1) % MAX == front)
        return; // Queue full

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

// Dequeue operation
void dequeue()
{
    if(front == -1)
        return; // Queue empty

    if(front == rear)
    {
        front = rear = -1;
        return;
    }

    front = (front + 1) % MAX;
}

// Display queue
void display()
{
    if(front == -1)
        return;

    int i = front;
    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    int n, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
        dequeue();

    display();

    return 0;
}