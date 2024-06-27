// Problem 609.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a node in a binary search tree, return the next bigger element, also known as the inorder successor.

For example, the inorder successor of 22 is 30.

   10
  /  \
 5    30
     /  \
   22    35
You can assume each node has a parent pointer.*/

#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {};
};

struct BinaryTree {
    Node* head = nullptr;

    BinaryTree() {}

    void addNodeRecursively(Node* current, int value) {
        if (value < current->value) {
            if (current->left == nullptr) {
                current->left = new Node(value);
                current->left->parent = current;
            }
            else {
                addNodeRecursively(current->left, value);
            }
        }
        else {
            if (current->right == nullptr) {
                current->right = new Node(value);
                current->right->parent = current;
            }
            else {
                addNodeRecursively(current->right, value);
            }
        }
    }

    void addNode(int value) {
        if (head == nullptr) {
            head = new Node(value);
        }
        else {
            addNodeRecursively(head, value);
        }
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }

    void printInOrder() {
        inOrderTraversal(head);
        cout << endl;
    }

    int nextHigherNode(int value) {
        Node* current = head;
        while (current->value != value) {
            if (value < current->value) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        if (current->right != nullptr) {
            current = current->right;
            while (current->left != nullptr) {
                current = current->left;
            }
            return current->value;
        }
        if (current == current->parent->left) {
            return current->parent->value;
        }
        while (current != current->parent->left) {
            current = current->parent;
        }
        return current->parent->value;
    }
};



int main()
{
    BinaryTree tree;
    tree.addNode(10);
    tree.addNode(5);
    tree.addNode(30);
    tree.addNode(22);
    tree.addNode(35);
    tree.addNode(25);
    tree.addNode(21);
    tree.addNode(26);
    tree.addNode(27);

    cout << tree.nextHigherNode(27) << endl;
    tree.printInOrder();
}
