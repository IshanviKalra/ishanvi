#include <stdio.h>
#include <stdlib.h>

// Structure for BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert into BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Function to display BST (Visual representation)
void displayBST(struct Node* root, int space) {
    if (root == NULL) return;
    space += 5;
    displayBST(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    displayBST(root->left, space);
}

// Linear Search Implementation
int linearSearch(int arr[], int n, int key, int *steps) {
    for (int i = 0; i < n; i++) {
        (*steps)++;
        if (arr[i] == key) return i;
    }
    return -1;
}

// Binary Search Implementation
int binarySearch(int arr[], int low, int high, int key, int *steps) {
    while (low <= high) {
        (*steps)++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n = 10;
    int data[10] = {12, 25, 33, 37, 48, 52, 64, 71, 89, 95}; // Sorted for Binary Search
    int target, choice, steps = 0;
    struct Node* root = NULL;

    // Building the BST from the data
    for(int i = 0; i < n; i++) root = insert(root, data[i]);

    printf("Dataset: ");
    for(int i = 0; i < n; i++) printf("%d ", data[i]);
    
    printf("\n\n--- Visual BST Representation ---\n");
    displayBST(root, 0);
    printf("----------------------------------\n");

    printf("\nEnter value to search: ");
    scanf("%d", &target);

    // Linear Search
    steps = 0;
    int lsResult = linearSearch(data, n, target, &steps);
    printf("\n[Linear Search] Index: %d, Steps taken: %d", lsResult, steps);

    // Binary Search
    steps = 0;
    int bsResult = binarySearch(data, 0, n - 1, target, &steps);
    printf("\n[Binary Search] Index: %d, Steps taken: %d\n", bsResult, steps);

    return 0;
}
