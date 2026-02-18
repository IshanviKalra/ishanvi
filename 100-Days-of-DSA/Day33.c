/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x)
{
    stack[++top] = x;
}

// Pop
char pop()
{
    return stack[top--];
}

// Check precedence
int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int k = 0;

    scanf("%s", infix);

    for(int i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        // Operand
        if(isalnum(ch))
        {
            postfix[k++] = ch;
        }
        // Left parenthesis
        else if(ch == '(')
        {
            push(ch);
        }
        // Right parenthesis
        else if(ch == ')')
        {
            while(stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        // Operator
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();

            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}