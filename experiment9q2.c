#include <stdio.h>
#define MAX 10

int isUndirected(int n, int adj[MAX][MAX]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(adj[i][j] != adj[j][i])
                return 0; // not symmetric
        }
    }
    return 1; // symmetric
}

int main() {
    int n;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if(isUndirected(n, adj))
        printf("\nGraph is Undirected (Matrix is symmetric).\n");
    else
        printf("\nGraph is Directed (Matrix is not symmetric).\n");

    return 0;
}