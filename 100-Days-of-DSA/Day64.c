/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// BFS function
void BFS(int start, int visited[], struct Node* adj[]) {
    int queue[MAX];
    int front = 0, rear = 0;

    // Mark visited and enqueue
    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];

        while(temp != NULL) {
            if(!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int s;
    scanf("%d", &s);

    BFS(s, visited, adj);

    return 0;
}