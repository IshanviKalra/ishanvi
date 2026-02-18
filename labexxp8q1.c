#include <stdio.h>

#define MAX 20

void printDegrees(int adj[MAX][MAX], int n, int v) {
    int inDegree = 0, outDegree = 0;

    for (int i = 0; i < n; i++) {
        // Out-degree: count edges leaving vertex v (check row v)
        if (adj[v][i] == 1) {
            outDegree++;
        }
        // In-degree: count edges entering vertex v (check column v)
        if (adj[i][v] == 1) {
            inDegree++;
        }
    }

    printf("\nVertex %d -> In-degree: %d, Out-degree: %d\n", v, inDegree, outDegree);
}

void displayMatrix(int adj[MAX][MAX], int n) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adj[MAX][MAX] = {0};
    int n, edges, u, v, searchVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source and destination) format 'u v':\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        if (u >= n || v >= n || u < 0 || v < 0) {
            printf("Invalid edge! Try again.\n");
            i--;
        } else {
            adj[u][v] = 1; // Directed graph
        }
    }
    displayMatrix(adj, n);

    printf("\nEnter the vertex 'i' to find its degrees: ");
    scanf("%d", &searchVertex);

    if (searchVertex >= 0 && searchVertex < n) {
        printDegrees(adj, n, searchVertex);
    } else {
        printf("Invalid vertex index.\n");
    }

    return 0;
}