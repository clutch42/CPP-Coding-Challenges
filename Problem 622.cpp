// Problem 622.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.

    a
   / \
  b   c
 /
d*/

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root;
    Tree(): root(nullptr){}
};

Node* findDeepestNode(Tree tree) {
    queue<Node*> nodes;
    nodes.push(tree.root);
    while (!nodes.empty()) {
        if (nodes.front()->right) {
            nodes.push(nodes.front()->right);
        }
        if (nodes.front()->left) {
            nodes.push(nodes.front()->left);
        }
        if (nodes.size() == 1) {
            return nodes.front();
        }
        nodes.pop();
    }
}

int main()
{
    Tree tree;
    tree.root = new Node('a');
    tree.root->left = new Node('b');
    tree.root->right = new Node('c');
    tree.root->left->left = new Node('d');
    tree.root->left->left->left = new Node('h');
    tree.root->left->left->left->left = new Node('g');
    tree.root->right->left = new Node('e');
    tree.root->right->left->left = new Node('f');

    Node* answer = findDeepestNode(tree);
    cout << answer->value << endl;

}
