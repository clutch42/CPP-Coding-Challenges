// Problem 587.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a binary tree, return all paths from the root to leaves.

For example, given the tree:

   1
  / \
 2   3
    / \
   4   5
Return [[1, 2], [1, 3, 4], [1, 3, 5]].*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    void findPaths(TreeNode* node, vector<int>& path, vector<vector<int>>& paths) {
        if (!node) {
            return;
        }

        path.push_back(node->value);

        if (!node->left && !node->right) {
            paths.push_back(path);
        }
        else {
            findPaths(node->left, path, paths);
            findPaths(node->right, path, paths);
        }
        
        path.pop_back();
    }

    vector<vector<int>> getPaths() {
        vector<vector<int>> paths;
        vector<int> path;
        findPaths(root, path, paths);
        return paths;
    }
};


int main() {
    BinaryTree tree1;
    tree1.root = new TreeNode(1);
    tree1.root->left = new TreeNode(2);
    tree1.root->right = new TreeNode(3);
    tree1.root->right->left = new TreeNode(4);
    tree1.root->right->right = new TreeNode(5);
    
    vector<vector<int>> paths = tree1.getPaths();
    // Print the paths
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
}

