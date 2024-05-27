// Problem 580.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a binary tree, find a minimum path sum from root to a leaf.
  10
 /  \
5    5
 \     \
   2    1
       /
     -1
For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.*/

#include <iostream>

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

    int findMinPathSum(TreeNode* node) {
        if (!node) return INT_MAX; // If the node is null, return a very large value (infinity)

        if (!node->left && !node->right) return node->value; // If the node is a leaf, return its value

        // Recursively find the minimum path sum for the left and right subtrees
        int leftSum = findMinPathSum(node->left);
        int rightSum = findMinPathSum(node->right);

        // Return the minimum path sum including the current node's value
        return node->value + std::min(leftSum, rightSum);
    }

    int getMinPathSum() {
        if (!root) return 0; // If the tree is empty, return 0
        return findMinPathSum(root);
    }
};

int main()
{
    BinaryTree tree;
    tree.root = new TreeNode(10);
    tree.root->left = new TreeNode(5);
    tree.root->right = new TreeNode(5);
    tree.root->left->right = new TreeNode(2);
    tree.root->right->right = new TreeNode(1);
    tree.root->right->right->left = new TreeNode(-1);

    std::cout << "Minimum path sum: " << tree.getMinPathSum() << std::endl; // Output: 15

    BinaryTree tree1;
    tree1.root = new TreeNode(10);

    std::cout << "Test Case 1 - Minimum path sum: " << tree1.getMinPathSum() << std::endl; // Expected output: 10

    BinaryTree tree2;
    tree2.root = new TreeNode(10);
    tree2.root->left = new TreeNode(5);
    tree2.root->right = new TreeNode(5);
    tree2.root->left->left = new TreeNode(2);
    tree2.root->left->right = new TreeNode(3);
    tree2.root->right->left = new TreeNode(1);
    tree2.root->right->right = new TreeNode(6);

    std::cout << "Test Case 2 - Minimum path sum: " << tree2.getMinPathSum() << std::endl; // Expected output: 16 (10 -> 5 -> 1)

    BinaryTree tree3;
    tree3.root = new TreeNode(10);
    tree3.root->right = new TreeNode(5);
    tree3.root->right->right = new TreeNode(3);
    tree3.root->right->right->right = new TreeNode(1);

    std::cout << "Test Case 3 - Minimum path sum: " << tree3.getMinPathSum() << std::endl; // Expected output: 19 (10 -> 5 -> 3 -> 1)

    BinaryTree tree4;
    tree4.root = new TreeNode(10);
    tree4.root->left = new TreeNode(5);
    tree4.root->left->left = new TreeNode(3);
    tree4.root->left->left->left = new TreeNode(1);

    std::cout << "Test Case 4 - Minimum path sum: " << tree4.getMinPathSum() << std::endl; // Expected output: 19 (10 -> 5 -> 3 -> 1)

    BinaryTree tree5;
    tree5.root = new TreeNode(10);
    tree5.root->left = new TreeNode(-5);
    tree5.root->right = new TreeNode(-3);
    tree5.root->left->left = new TreeNode(2);
    tree5.root->right->right = new TreeNode(-1);

    std::cout << "Test Case 5 - Minimum path sum: " << tree5.getMinPathSum() << std::endl; // Expected output: 6 (10 -> -3 -> -1)

    BinaryTree tree6;

    std::cout << "Test Case 6 - Minimum path sum: " << tree6.getMinPathSum() << std::endl; // Expected output: 0


    return 0;
}
