#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ishanvi[5];

    for (int i = 0; i < n; i++) {
        ishanvi[i] = arr[n - i - 1];
    }

    printf("Elements of new array ishanvi in reverse order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ishanvi[i]);
    }

    return 0;
}