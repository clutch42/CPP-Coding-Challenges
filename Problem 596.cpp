// Problem 596.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() : root(nullptr) {}

    void printBinaryTree() {
        if (this->root == nullptr) {
            return;
        }

        queue<TreeNode*> q;
        q.push(this->root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                cout << current->value << " ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            std::cout << std::endl; // Newline for new level
        }
    }

    void invert(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        invert(node->left);
        invert(node->right);
    }

    void invertTree() {
        /*if (this->root == nullptr) {
            return;
        }*/
        invert(this->root);
    }
};

int main()
{
    BinaryTree tree;
    tree.root = new TreeNode('a');
    tree.root->left = new TreeNode('b');
    tree.root->right = new TreeNode('c');
    tree.root->left->left = new TreeNode('d');
    tree.root->left->right = new TreeNode('e');
    tree.root->right->left = new TreeNode('f');
    tree.printBinaryTree();
    tree.invertTree();
    tree.printBinaryTree();
    BinaryTree tree2;
    tree2.printBinaryTree();
    tree2.invertTree();
    tree2.printBinaryTree();
    BinaryTree tree3;
    tree3.root = new TreeNode('a');
    tree3.printBinaryTree();
    tree3.invertTree();
    tree3.printBinaryTree();
    BinaryTree tree4;
    tree4.root = new TreeNode('a');
    tree4.root->left = new TreeNode('b');
    tree4.root->right = new TreeNode('c');
    tree4.printBinaryTree();
    tree4.invertTree();
    tree4.printBinaryTree();
}
