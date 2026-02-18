#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// BST Node Structure
struct node {
    int data;
    struct node *left, *right;
};

// Naya node banane ka function
struct node* create(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Logic: Left mein Smaller, Right mein Bigger
struct node* insert(struct node* root, int val) {
    if (root == NULL) return create(val);
    
    if (val < root->data) {
        root->left = insert(root->left, val); // Smaller goes Left
    } else {
        root->right = insert(root->right, val); // Bigger goes Right
    }
    return root;
}

// Tree ko visual edges ke saath print karne ka function
void printTree(struct node* root, int space) {
    if (root == NULL) return;

    // Levels ke beech ki doori (spacing)
    space += 10;

    // Pehle Right child print hoga (Top pe dikhega)
    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) printf(" ");
    
    // Node value with edge symbol
    printf("|--- %d\n", root->data);

    // Phir Left child print hoga (Bottom pe dikhega)
    printTree(root->left, space);
}

// Search function to count steps
int searchBST(struct node* root, int key, int *steps) {
    while (root != NULL) {
        (*steps)++;
        if (root->data == key) return 1;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return 0;
}

int main() {
    int n = 10;
    int arr[10];
    int key, stepsBST = 0;
    struct node* root = NULL;

    srand(time(0));

    printf("--- Generating 10 Random Elements ---\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // 0-99 ke beech ke numbers
        printf("%d ", arr[i]);
        root = insert(root, arr[i]);
    }

    printf("\n\nEnter number to search: ");
    scanf("%d", &key);

    printf("\n--- Visual BST Tree (Sideways View) ---\n");
    printf("(Read: Right is UP, Left is DOWN)\n");
    printTree(root, 0);

    // BST Search Execution
    int found = searchBST(root, key, &stepsBST);

    printf("\n--- BST Search Result ---\n");
    if (found) printf("Status: Found!\n");
    else printf("Status: Not Found.\n");
    printf("Total Steps taken in Tree: %d\n", stepsBST);

    return 0;
}