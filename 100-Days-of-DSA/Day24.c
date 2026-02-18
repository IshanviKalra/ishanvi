/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/

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

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key)
{
    if(head == NULL)
        return head;

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head itself contains key
    if(temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    // Traverse list
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key found
    if(temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }

    return head;
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

    int key;
    scanf("%d", &key);

    head = deleteKey(head, key);

    // Print updated list
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}