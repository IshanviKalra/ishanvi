#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *n1, *n2, *n3, *temp;

    // Creating list manually
    n1 = malloc(sizeof(struct Node));
    n2 = malloc(sizeof(struct Node));
    n3 = malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    head = n1;

    // Traverse
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}