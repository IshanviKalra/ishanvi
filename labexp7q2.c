#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Define the table size

int hashTable[SIZE];

// Initialize the hash table with -1 (indicating empty)
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function based on last three digits (S.No.1 reference)
int hashFunction(int key) {
    return (key % 1000) % SIZE;
}

// Insert operation with Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE; // Move to next slot
        if (index == originalIndex) {
            printf("Hash Table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search operation
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
        if (index == originalIndex) break;
    }
    return -1;
}

// Delete operation (using -2 as a 'deleted' marker to keep the probe chain intact)
void delete(int key) {
    int index = search(key);
    if (index != -1) {
        hashTable[index] = -1; // Simplification: setting back to empty
        printf("Deleted %d from index %d\n", key, index);
    } else {
        printf("Key %d not found for deletion.\n", key);
    }
}

void display() {
    printf("\nHash Table State:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

int main() {
    init();
    
    // Example: Inserting SAP IDs
    insert(5000425); // Hash: 425 % 10 = 5
    insert(5000435); // Hash: 435 % 10 = 5 (Collision! Probes to index 6)
    insert(5000426); // Hash: 426 % 10 = 6 (Collision! Probes to index 7)

    display();

    int find = 5000435;
    int pos = search(find);
    if(pos != -1) printf("\nFound %d at index %d\n", find, pos);
    else printf("\n%d not found\n", find);

    delete(5000425);
    display();

    return 0;
}