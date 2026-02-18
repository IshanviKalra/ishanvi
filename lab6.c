#include <stdio.h>

int main(){
    int a[3][3]={{0,0,3},{0,4,0},{5,0,0}};
    int i,j;

    printf("Row Col Value\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(a[i][j]!=0)
                printf("%d   %d   %d\n",i,j,a[i][j]);

    return 0;
}