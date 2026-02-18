#include <stdio.h>

int main() {
    int a[10][10], r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    // Row sum
    for (i = 0; i < r; i++) {
        int sum = 0;
        for (j = 0; j < c; j++)
            sum += a[i][j];
        printf("Sum of row %d = %d\n", i + 1, sum);
    }

    // Column sum
    for (j = 0; j < c; j++) {
        int sum = 0;
        for (i = 0; i < r; i++)
            sum += a[i][j];
        printf("Sum of column %d = %d\n", j + 1, sum);
    }

    return 0;
}
