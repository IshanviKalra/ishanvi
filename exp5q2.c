#include <stdio.h>
#define SIZE 7
int tree[SIZE] = {1, 2, 3, 4, 5, 6, 7};
void inorder(int i) {
    if (i >= SIZE) return;
    inorder(2*i + 1);       // left child
    printf("%d ", tree[i]); // root
    inorder(2*i + 2);       // right child
}
void preorder(int i) {
    if (i >= SIZE) return;
    printf("%d ", tree[i]); // root
    preorder(2*i + 1);      // left child
    preorder(2*i + 2);      // right child
}
void postorder(int i) {
    if (i >= SIZE) return;
    postorder(2*i + 1);     // left child
    postorder(2*i + 2);     // right child
    printf("%d ", tree[i]); // root
}
int main() {
    printf("Inorder: ");
    inorder(0);
    printf("\nPreorder: ");
    preorder(0);
    printf("\nPostorder: ");
    postorder(0);
    return 0;
}