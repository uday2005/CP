// What Are Previsit and Postvisit?
// previsit(v): Called immediately after marking node 
// v
// v as visited, but before exploring its neighbors.
// Use: Record the time you enter 
// v
// v, or do any setup before recursion.

// postvisit(v): Called after all neighbors of 
// v
// v have been explored.
// Use: Record the time you leave 
// v
// v, or do any cleanup/processing after recursion.

// Why Use Them?

// DFS entry/exit timestamps (for algorithms like Kosaraju’s for SCCs, topological sort, etc.)

// Cycle detection (by comparing pre/post numbers)

// Building traversal orders (like pre-order and post-order traversals)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;      // Adjacency list
vector<bool> visited;         // Visited array
vector<int> pre, post;        // Previsit and postvisit times
int clockTime = 1;            // Global clock

void previsit(int v) {
    pre[v] = clockTime++;
    // You can add other logic here if needed
}

void postvisit(int v) {
    post[v] = clockTime++;
    // You can add other logic here if needed
}

void Explore(int v) {
    visited[v] = true;
    previsit(v);
    for (int w : adj[v]) {
        if (!visited[w]) {
            Explore(w);
        }
    }
    postvisit(v);
}

int main() {
    int n = 5; // Number of nodes
    adj.resize(n);
    visited.assign(n, false);
    pre.resize(n, 0);
    post.resize(n, 0);

    // Example graph
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Run DFS from node 0
    Explore(0);

    // Output previsit and postvisit times
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": pre = " << pre[i] << ", post = " << post[i] << endl;
    }

    return 0;
}
