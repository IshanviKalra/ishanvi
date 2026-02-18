#include <stdio.h>
#define MAX 10

void printMatrix(int n, int adj[MAX][MAX]) {
    printf("\nAdjacency Matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int inDegree(int n, int adj[MAX][MAX], int v) {
    int count = 0;
    for(int i=0; i<n; i++) count += adj[i][v];
    return count;
}

int outDegree(int n, int adj[MAX][MAX], int v) {
    int count = 0;
    for(int j=0; j<n; j++) count += adj[v][j];
    return count;
}

int main() {
    int n, e, u, v;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for(int i=0; i<e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    printMatrix(n, adj);

    printf("\nEnter vertex to find degree: ");
    scanf("%d", &v);

    printf("In-degree of vertex %d = %d\n", v, inDegree(n, adj, v));
    printf("Out-degree of vertex %d = %d\n", v, outDegree(n, adj, v));

    return 0;
}