/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/

#include <stdio.h>

// Recursive function to print string in reverse
void mirror(char str[], int index)
{
    if(str[index] == '\0')
        return;

    mirror(str, index + 1);
    printf("%c", str[index]);
}

int main()
{
    char str[100];

    // Input string
    scanf("%s", str);

    // Call recursive function
    mirror(str, 0);

    return 0;
}
