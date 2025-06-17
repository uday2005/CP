#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // (distance, node)

void dijkstra(const vector<vector<pii>>& graph, int src, vector<int>& dist, vector<int>& prev) {
    int n = graph.size();
    dist.assign(n, INT_MAX);
    prev.assign(n, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap

    // Naturally priority queue is a max heap which means highest element at the top 
    // but by doing greater<pii> we are making it a min heap.

    dist[src] = 0;
    pq.push({0, src}); // is first it store distance and second from where

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue; // Skip outdated entries

        for (const pii& edge : graph[u]) {
            int v = edge.first, w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void printPath(const vector<int>& prev, int v) {
    if (v == -1) return;
    printPath(prev, prev[v]);
    cout << v << " ";
}

int main() {
    int n = 4; // Nodes: 0, 1, 2, 3
    vector<vector<pii>> graph(n);

    // Build graph (node, weight)
    graph[0].emplace_back(1, 4);
    graph[0].emplace_back(2, 1);
    graph[2].emplace_back(1, 2);
    graph[1].emplace_back(3, 1);
    graph[2].emplace_back(3, 5);

    vector<int> dist, prev;
    dijkstra(graph, 0, dist, prev);

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "Unreachable";
        else cout << dist[i] << " (Path: ";
        printPath(prev, i);
        if (dist[i] != INT_MAX) cout << ")";
        cout << endl;
    }
    return 0;
}
