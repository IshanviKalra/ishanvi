/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdlib.h>

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

// DFS cycle detection
int dfs(int v, int visited[], struct Node* adj[], int parent) {
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        int neighbor = temp->data;

        if(!visited[neighbor]) {
            if(dfs(neighbor, visited, adj, v))
                return 1;
        }
        else if(neighbor != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
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

    // Check all components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, visited, adj, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}