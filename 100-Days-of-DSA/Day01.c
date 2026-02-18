/* Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/

#include <stdio.h>

int main()
{
    int n, pos, x;
    
    // Step 1: Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n + 1]; // extra space for new element

    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Step 3: Input position
    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    // Step 4: Input element to insert
    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Step 5: Shift elements to right
    for(int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Step 6: Insert element
    arr[pos - 1] = x;

    // Step 7: Print updated array
    printf("Updated array:\n");
    for(int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

