/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

// Function to insert at end
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

// Function to merge two sorted lists
struct Node* merge(struct Node* head1, struct Node* head2)
{
    struct Node* merged = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            merged = insert(merged, head1->data);
            head1 = head1->next;
        }
        else
        {
            merged = insert(merged, head2->data);
            head2 = head2->next;
        }
    }

    // Add remaining elements
    while(head1 != NULL)
    {
        merged = insert(merged, head1->data);
        head1 = head1->next;
    }

    while(head2 != NULL)
    {
        merged = insert(merged, head2->data);
        head2 = head2->next;
    }

    return merged;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        head1 = insert(head1, value);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        int value;
        scanf("%d", &value);
        head2 = insert(head2, value);
    }

    struct Node* mergedHead = merge(head1, head2);

    // Print merged list
    struct Node* temp = mergedHead;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}