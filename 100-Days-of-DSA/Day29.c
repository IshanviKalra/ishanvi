/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

// Insert at end
struct Node* insert(struct Node* head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Find length
int length(struct Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Rotate right by k places
struct Node* rotateRight(struct Node* head, int k)
{
    if(head == NULL || head->next == NULL)
        return head;

    int n = length(head);
    k = k % n;

    if(k == 0)
        return head;

    struct Node* temp = head;

    // Reach last node
    while(temp->next != NULL)
        temp = temp->next;

    // Make circular list
    temp->next = head;

    int steps = n - k;

    temp = head;
    for(int i = 1; i < steps; i++)
        temp = temp->next;

    // New head
    struct Node* newHead = temp->next;

    // Break circle
    temp->next = NULL;

    return newHead;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        head = insert(head, value);
    }

    int k;
    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print rotated list
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}