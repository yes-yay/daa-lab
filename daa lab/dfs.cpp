//sri rama jayam 
#include <iostream>
#include <stack>
using namespace std;

struct node {
    int v;
    struct node* next; 
};

struct graph {
    int V;
    struct node* adjList[100];
};

struct node* createNode(int v) {
    struct node* temp = new struct node;
    temp->next = nullptr;
    temp->v = v;
    return temp;
}

struct graph* createGraph(int v) {
    struct graph* g = new struct graph;
    g->V = v;
    for (int i = 0; i < v; i++) {
        g->adjList[i] = nullptr;
    }
    return g;
}

void addEdge(struct graph* g, int src, int dest) {
    // Edge from src to dest.
    struct node* srcNode = createNode(src);
    srcNode->next = g->adjList[dest];
    g->adjList[dest] = srcNode;

    // Edge from dest to src.
    struct node* destNode = createNode(dest);
    destNode->next = g->adjList[src];
    g->adjList[src] = destNode;
}

bool DFSRecursive(struct graph* g, int vertex, int visited[], int parent) {
    visited[vertex] = 1;

    struct node* temp = g->adjList[vertex];
    while (temp != nullptr) {
        int adjVertex = temp->v;

        if (!visited[adjVertex]) {
            if (DFSRecursive(g, adjVertex, visited, vertex)) {
                return true; // Cycle found in the subtree
            }
        } else if (adjVertex != parent) {
            return true; // Back edge indicates a cycle
        }

        temp = temp->next;
    }

    return false;
}

bool isCyclic(struct graph* g) {
    int visited[g->V];
    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < g->V; i++) {
        if (!visited[i] && DFSRecursive(g, i, visited, -1)) {
            return true; // A cycle was found
        }
    }

    return false;
}

int main() {
    struct graph* g = createGraph(4);
    addEdge(g, 0, 1);
    // addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);

    if (isCyclic(g)) {
        cout << "Cyclic";
    } else {
        cout << "Not Cyclic";
    }

    return 0;
}
