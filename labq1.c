#include <stdio.h>

int main() {
    int arr[] = {6,4,8,10,12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Linear Traversal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}