#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj; // adjacency list
vector<bool> visited;

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " "; // process node

        for (int w : adj[v]) {
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }
}

int main() {
    int n = 5;
    adj.resize(n);
    visited.assign(n, false);

    // Example undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    BFS(0); // Start BFS from node 0

    return 0;
}