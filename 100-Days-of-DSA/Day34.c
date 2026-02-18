/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop()
{
    if(top == NULL)
        return -1;

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Evaluate postfix
int evaluate(char expr[])
{
    int i = 0;

    while(expr[i] != '\0')
    {
        // Skip spaces
        if(expr[i] == ' ')
        {
            i++;
            continue;
        }

        // If digit
        if(isdigit(expr[i]))
        {
            int num = 0;
            while(isdigit(expr[i]))
            {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            push(num);
        }
        else
        {
            int val2 = pop();
            int val1 = pop();

            switch(expr[i])
            {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
            i++;
        }
    }

    return pop();
}

int main()
{
    char expr[100];

    fgets(expr, sizeof(expr), stdin);

    int result = evaluate(expr);

    printf("%d", result);

    return 0;
}