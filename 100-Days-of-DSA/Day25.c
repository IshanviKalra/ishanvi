/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/

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

int main()
{
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    // Create linked list
    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        head = insert(head, value);
    }

    int key;
    scanf("%d", &key);

    // Count occurrences
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
            count++;

        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}