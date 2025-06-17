// if we want to lets say find  the connected components so,

// Modify the explore fucntion for diffent components

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;      // Adjacency list
vector<bool> visited;         // Visited array

void Explore2(int v , vector<int> & component){
    visited[v] = true;
    component.push_back(v);

    for( int w : adj[v]){
        if(!visited[w]){
            Explore2(w,component);
        }
    }
}

vector<vector<int>> find_All_Compo(int n){
    visited.assign(n , false);

    vector<vector<int>> components;

    for( int v = 0; v < n; v++){
        if(! visited[v]){
            vector<int> component;
            Explore2(v , component);
            components.push_back(component);
        }
    }
    return components;
}

int main() {
    int n = 6; // Example: 6 nodes (0 to 5)
    adj.resize(n);

    // Example graph with two components: {0,1,2} and {3,4,5}
    adj[0] = {1};
    adj[1] = {0,2};
    adj[2] = {1};
    adj[3] = {4,5};
    adj[4] = {3,5};
    adj[5] = {3,4};

     vector<vector<int>> components = find_All_Compo(n);

    // Output all components
    for (int i = 0; i < components.size(); ++i) {
        cout << "Component " << i+1 << ": ";
        for (int v : components[i]) cout << v << " ";
        cout << endl;
    }
    return 0;
}

