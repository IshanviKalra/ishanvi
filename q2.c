#include <stdio.h>

int main() {
    int a1[100], n, i, pos, elem, del;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a1[i]);

    // Insert
    printf("Enter position to insert and element: ");
    scanf("%d %d", &pos, &elem);

    for (i = n; i >= pos; i--)
        a1[i] = a1[i - 1];
    a1[pos - 1] = elem;
    n++;

    printf("Array after insertion:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a1[i]);

    // Delete
    printf("\nEnter position to delete: ");
    scanf("%d", &del);

    for (i = del - 1; i < n - 1; i++)
        a1[i] = a1[i + 1];
    n--;

    printf("Array after deletion:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a1[i]);

    return 0;
}
