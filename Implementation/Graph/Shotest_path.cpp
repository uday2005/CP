#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

void bfsShortestDistance(const unordered_map<string, vector<string>> &graph, const string &start)
{

    unordered_map<string, int> dist;

    queue<string> q;

    for (const auto &node : graph)
    {
        dist[node.first] = -1; // means not visited
    }

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        string u = q.front();
        q.pop();

        for (const string &v : graph.at(u))
        {

            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "Shortest distance from " << start << ":\n";
    for (const auto &p : dist)
    {
        if (p.second != -1)
            cout << p.first << ": " << p.second << endl;
    }
}

int main()
{
    unordered_map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"A", "D", "E"}},
        {"C", {"A", "F"}},
        {"D", {"B"}},
        {"E", {"B", "F"}},
        {"F", {"C", "E"}}};
    bfsShortestDistance(graph, "A");
    return 0;
}
