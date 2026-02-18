/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

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
int dfs(int v, int visited[], int recStack[], struct Node* adj[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        int neighbor = temp->data;

        if(!visited[neighbor]) {
            if(dfs(neighbor, visited, recStack, adj))
                return 1;
        }
        else if(recStack[neighbor]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
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

    // Input directed edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[n], recStack[n];

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Check all components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, visited, recStack, adj)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}