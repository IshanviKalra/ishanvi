#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert
void insert(int value) {
    size++;
    heap[size] = value;

    int i = size;

    // Heapify up
    while (i > 1 && heap[i] > heap[i/2]) {
        swap(&heap[i], &heap[i/2]);
        i = i / 2;
    }
}

// Delete root
void deleteRoot() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    heap[1] = heap[size];
    size--;

    int i = 1;

    // Heapify down
    while (2*i <= size) {
        int largest = i;

        if (heap[2*i] > heap[largest])
            largest = 2*i;

        if (2*i+1 <= size && heap[2*i+1] > heap[largest])
            largest = 2*i+1;

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else
            break;
    }
}

// Display
void display() {
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
}

// MAIN FUNCTION
int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);

    printf("Heap: ");
    display();

    deleteRoot();

    printf("\nAfter Deletion: ");
    display();

    return 0;
}