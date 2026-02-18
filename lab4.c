#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef, exp;
    struct node *next;
};

int main(){
    struct node *p = NULL, *n;

    n = (struct node*)malloc(sizeof(struct node));
    n->coef=5; n->exp=2;
    n->next=NULL;
    p=n;

    printf("Polynomial: %dx^%d\n", p->coef, p->exp);
    return 0;
}