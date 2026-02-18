#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insert(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->prev = NULL;
    n->next = head;

    if (head)
        head->prev = n;

    head = n;
}

// Delete from beginning
void delete() {
    if (!head) return;

    struct Node* temp = head;
    head = head->next;

    if (head)
        head->prev = NULL;

    free(temp);
}

// Display
void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();

    delete();
    display();

    return 0;
}