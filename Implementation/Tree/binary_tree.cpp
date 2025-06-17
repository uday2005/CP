#include <bits/stdc++.h>
using namespace std;




class binary_tree{

    private:
        // Definition for a binary tree node
    class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    public:
        binary_tree() : root(nullptr){};

        ~binary_tree() {

        }

    
    void populate(){
        int val ;
        cout << "Enter the root Node value";
        cin >> val;

        root = new Node(val);

        insert(root);

    }

    void insert(Node* node){
        int val;
        char choice;

        // Left child
        cout << "Add left child of " << node->data << "? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter value for left child of " << node->data << ": ";
            cin >> val;
            node->left = new Node(val);
            insert(node->left);
        }

        // Right child
        cout << "Add right child of " << node->data << "? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter value for right child of " << node->data << ": ";
            cin >> val;
            node->right = new Node(val);
            insert(node->right);
        }
    }

      // Helper function for inorder traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};