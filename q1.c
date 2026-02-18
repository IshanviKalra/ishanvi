#include <stdio.h>

int sum(int a[], int n) {
    if (n == 0)
        return 0;
    return a[n - 1] + sum(a, n - 1);
}

int main() {
    int n, i;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Sum of elements = %d", sum(a, n));
    return 0;
}
