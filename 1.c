#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertBeg(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = head;
    head = n;
}

// Insert at end
void insertEnd(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;

    if (!head) { head = n; return; }

    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

// Insert at position
void insertPos(int val, int pos) {
    if (pos == 1) { insertBeg(val); return; }

    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;

    struct Node* t = head;
    for (int i = 1; i < pos-1 && t; i++)
        t = t->next;

    if (!t) return;

    n->next = t->next;
    t->next = n;
}

// Delete at position
void deletePos(int pos) {
    if (!head) return;

    if (pos == 1) {
        struct Node* t = head;
        head = head->next;
        free(t);
        return;
    }

    struct Node* t = head;
    for (int i = 1; i < pos-1 && t->next; i++)
        t = t->next;

    if (!t->next) return;

    struct Node* del = t->next;
    t->next = del->next;
    free(del);
}

// Display
void display() {
    struct Node* t = head;
    while (t) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    insertBeg(10);
    insertEnd(20);
    insertPos(15, 2);
    display();

    deletePos(2);
    display();

    return 0;
}