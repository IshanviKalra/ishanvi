#include <stdio.h>
#include <string.h>

#define SIZE 100

char queue[SIZE], stack[SIZE];
int front = 0, rear = -1, top = -1;

void enqueue(char ch) {
    queue[++rear] = ch;
}

void push(char ch) {
    stack[++top] = ch;
}

char dequeue() {
    return queue[front++];
}

char pop() {
    return stack[top--];
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        enqueue(str[i]);
        push(str[i]);
    }

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (dequeue() != pop()) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}