#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop(){
    if(top==NULL) printf("Underflow\n");
    else{
        struct node *t = top;
        printf("Deleted: %d\n", top->data);
        top = top->next;
        free(t);
    }
}

void display(){
    struct node *t = top;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main(){
    push(10); push(20); push(30);
    display();
    pop();
    display();
}