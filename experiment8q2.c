#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash Function (Digital Root)
int hashFunction(int sapID) {
    int last3 = sapID % 1000;
    int sum = 0;

    while (last3 > 0) {
        sum += last3 % 10;
        last3 /= 10;
    }

    while (sum >= 10) {
        int temp = 0;
        while (sum > 0) {
            temp += sum % 10;
            sum /= 10;
        }
        sum = temp;
    }

    return sum % SIZE;
}

// Insert with Linear Probing
void insert(int sapID) {
    int index = hashFunction(sapID);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == originalIndex) {
            printf("Hash Table is Full!\n");
            return;
        }
    }

    hashTable[index] = sapID;
    printf("Inserted at index %d\n", index);
}

// Search with Linear Probing
void search(int sapID) {
    int index = hashFunction(sapID);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == sapID) {
            printf("Element found at index %d\n", index);
            return;
        }
        index = (index + 1) % SIZE;

        if (index == originalIndex)
            break;
    }

    printf("Element not found\n");
}

// Delete with Linear Probing
void deleteElement(int sapID) {
    int index = hashFunction(sapID);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == sapID) {
            hashTable[index] = -1;
            printf("Element deleted\n");
            return;
        }
        index = (index + 1) % SIZE;

        if (index == originalIndex)
            break;
    }

    printf("Element not found\n");
}

// Display
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d --> %d\n", i, hashTable[i]);
}

// Main
int main() {
    int choice, sapID;

    init();

    do {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter SAP-ID: ");
                scanf("%d", &sapID);
                insert(sapID);
                break;

            case 2:
                printf("Enter SAP-ID: ");
                scanf("%d", &sapID);
                search(sapID);
                break;

            case 3:
                printf("Enter SAP-ID: ");
                scanf("%d", &sapID);
                deleteElement(sapID);
                break;

            case 4:
                display();
                break;
        }

    } while (choice != 5);

    return 0;
}