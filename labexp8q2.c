#include <stdio.h>

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int isUndirected = 1;

    // Check symmetry
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] != graph[j][i]) {
                isUndirected = 0;
                break;
            }
        }
        if(isUndirected == 0)
            break;
    }

    if(isUndirected)
        printf("Graph is Undirected\n");
    else
        printf("Graph is Directed\n");

    return 0;
}