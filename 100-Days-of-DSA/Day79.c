/* Problem:
Find shortest distance from source using Dijkstra's Algorithm.
*/

#include <stdio.h>
#include <limits.h>

int minDist(int dist[], int visited[], int n) {
    int min = INT_MAX, index;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int n = 5;
    int graph[5][5] = {
        {0,2,4,0,0},
        {2,0,1,7,0},
        {4,1,0,0,3},
        {0,7,0,0,1},
        {0,0,3,1,0}
    };

    int dist[n], visited[n];

    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    int src = 0;
    dist[src] = 0;

    for(int i = 0; i < n-1; i++) {
        int u = minDist(dist, visited, n);
        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(!visited[v] && graph[u][v] &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}