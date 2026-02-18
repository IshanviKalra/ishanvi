#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search: Checks every index one by one
int linearSearch(int arr[], int size, int target, int* steps) {
    *steps = 0;
    for (int i = 0; i < size; i++) {
        (*steps)++;
        if (arr[i] == target) return i; 
    }
    return -1; 
}

// Binary Search: Jumps to middle, cuts list in half
int binarySearch(int arr[], int size, int target, int* steps) {
    int low = 0, high = size - 1;
    *steps = 0;
    while (low <= high) {
        (*steps)++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Helper for sorting (needed for Binary Search)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n = 1000;
    int data[n];
    int target, linearSteps = 0, binarySteps = 0;

    srand(time(NULL));

    // 1. Generate and Print 1000 random elements
    printf("--- Generating 1000 Random Elements ---\n");
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 2000; // Random numbers 0-1999
        printf("%d ", data[i]);
    }

    // 2. User Input for the target
    printf("\n\n--------------------------------------------\n");
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);
    printf("--------------------------------------------\n");

    // 3. Perform Linear Search
    int linResult = linearSearch(data, n, target, &linearSteps);

    // 4. Sort and Perform Binary Search
    qsort(data, n, sizeof(int), compare);
    int binResult = binarySearch(data, n, target, &binarySteps);

    // 5. Output Results
    if (linResult != -1) {
        printf("\nSuccess! Element found.");
        printf("\nLinear Search Steps: %d", linearSteps);
        printf("\nBinary Search Steps: %d\n", binarySteps);
    } else {
        printf("\nElement %d was not found in the random data.\n", target);
        printf("Linear Search checked all %d elements.\n", linearSteps);
    }

    return 0;
}