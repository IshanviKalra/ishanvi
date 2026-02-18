#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

// Insert at end
void insert(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;

    if (!last) {
        last = n;
        n->next = n;
    } else {
        n->next = last->next;
        last->next = n;
        last = n;
    }
}

// Delete from beginning
void delete() {
    if (!last) return;

    struct Node* temp = last->next;

    if (last == temp)
        last = NULL;
    else
        last->next = temp->next;

    free(temp);
}

// Display
void display() {
    if (!last) return;

    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(circular)\n");
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