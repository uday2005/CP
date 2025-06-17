#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void Explore(int v)
{
    visited[v] = true;

    for (int w : adj[v])
    {
        if (!visited[w])
        {
            Explore(w);
        }
    }
}

// If want to do complete search
// it will also explore the node even though the graph is dicconnected

void DFS(int n)
{
    visited.assign(n, false);

    for (int v = 0; v < n; v++)
    {
        if (!visited[v])
        {
            Explore(v);
        }
    }
}

int main()
{
    int n = 5;

    adj.resize(n); // No of vertices

    visited.resize(n, false); // Visited all set to the false

    // Build the adjacency list

    // In undirected graphs add  both directions for every edge

    // adj[u] = {..., v, ...};
    // adj[v] = {..., u, ...};

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {};

    // Started to Explore from zero
    // Explore(0);
    DFS(5);

    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << " visited: " << visited[i] << endl;
    }

    return 0;
}


// What if we need some information about node as now its only marking the node if it si visited.
// So we can use the previsit and postvisit.




