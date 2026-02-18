/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    int indegree[n];

    // Initialize
    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    int u, v;

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++; // increase indegree
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push all nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    // Process queue
    while(front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];

        while(temp != NULL) {
            indegree[temp->data]--;

            if(indegree[temp->data] == 0)
                queue[rear++] = temp->data;

            temp = temp->next;
        }
    }

    // Cycle check
    if(count != n)
        printf("\nCycle Exists");

    return 0;
}