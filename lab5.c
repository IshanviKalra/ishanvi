#include <stdio.h>

int main(){
    int a[3]={2,3,4};   // 2x^2+3x+4
    int b[3]={1,5,6};   // 1x^2+5x+6
    int c[3], i;

    for(i=0;i<3;i++)
        c[i]=a[i]+b[i];

    printf("Sum: %dx^2 + %dx + %d", c[0],c[1],c[2]);
    return 0;
}