#include <stdio.h>
#define MAX 5

int stack[MAX], top=-1;

void push(int x){
    if(top==MAX-1) printf("Overflow\n");
    else stack[++top]=x;
}

void pop(){
    if(top==-1) printf("Underflow\n");
    else printf("Deleted: %d\n", stack[top--]);
}

int main(){
    push(5); push(15); push(25);
    pop();
    return 0;
}