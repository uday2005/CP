#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;   // Adjacency list
vector<bool> visited;
stack<int> order;          // Stack to store reverse post-order

void dfs(int v) {
    visited[v] = true;
    for (int w : adj[v]) {
        if (!visited[w]) {
            dfs(w);
        }
    }
    order.push(v); // Postvisit: push onto stack
}

vector<int> topologicalSort(int n) {
    visited.assign(n, false);
    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    vector<int> topo;
    while (!order.empty()) {
        topo.push_back(order.top());
        order.pop();
    }
    return topo; // This is the topological order
}

int main() {
    int n = 6;
    adj.resize(n);

    // Example DAG:
    // 5 → 2, 5 → 0, 4 → 0, 4 → 1, 2 → 3, 3 → 1
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    adj[0] = {};
    adj[1] = {};

    vector<int> topo = topologicalSort(n);

    cout << "Topological Sort: ";
    for (int v : topo) cout << v << " ";
    cout << endl;
    return 0;
}
