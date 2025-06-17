#include <bits/stdc++.h>
using namespace std;

#include <queue>

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// BFS
void LevelTraversal(Node* tree) {

    if(tree == nullptr) return;

    queue<Node* >q;
    q.push(tree); // pushing the root node

    while(!q.empty()){

        Node* node = q.front();
        q.pop();

        cout << node->data << " ";

        if(node -> left != nullptr){
            q.push(node -> left);
        }
        if(node -> right != nullptr){
            q.push(node -> right);
        }
    }

}