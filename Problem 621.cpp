// Problem 621.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char name;
    vector<pair<Node*, int>> attachedNodes;

    Node(char n) : name(n) {};
};

struct Graph {
    vector<Node*> nodes;
    
    Graph() {};

    void addNewNode(char c) {
        nodes.push_back(new Node(c));
    }
    void addConnection(int value, char node1Name, char node2Name) {
        Node* node1 = nullptr;
        Node* node2 = nullptr;
        for (auto n : nodes) {
            if (n->name == node1Name) {
                node1 = n;
            }
            else if (n->name == node2Name) {
                node2 = n;
            }
        }
        if (node1 == nullptr || node2 == nullptr) {
            return;
        }
        node1->attachedNodes.push_back({ node2, value });
        node2->attachedNodes.push_back({ node1, value });
    }

    void printNodes() {
        for (auto n : nodes) {
            cout << n->name << ": ";
            for (auto each : n->attachedNodes) {
                cout << each.first->name << ": " << each.second << "   ";
            }
            cout << endl;
        }
    }

    int findPath(Node* current, Node* parent) {
        if (current->attachedNodes.empty()) {
            return 0;
        }
        int maxSum = 0;
        for (auto node : current->attachedNodes) {
            if (node.first != parent) {
                int pathSum = node.second + findPath(node.first, current);
                if (pathSum > maxSum) {
                    maxSum = pathSum;
                }
            }
        }
        
        return maxSum;
    }

    int longestPath() {
        int length = 0;
        int max = 0;
        for (auto n : nodes) {
            length = findPath(n, nullptr);
            if (length > max) {
                max = length;
            }
        }
        return max;
    }
};



int main()
{
    Graph graph;
    graph.addNewNode('a');
    graph.addNewNode('b');
    graph.addNewNode('c');
    graph.addNewNode('d');
    graph.addNewNode('e');
    graph.addNewNode('f');
    graph.addNewNode('g');
    graph.addNewNode('h');
    graph.addConnection(3, 'a', 'b');
    graph.addConnection(5, 'a', 'c');
    graph.addConnection(8, 'a', 'd');
    graph.addConnection(2, 'd', 'e');
    graph.addConnection(4, 'd', 'f');
    graph.addConnection(1, 'e', 'g');
    graph.addConnection(1, 'e', 'h');
    graph.printNodes();
    cout << "Longest path: " << graph.longestPath() << endl;
    graph.addNewNode('i');
    graph.addConnection(100, 'a', 'i');
    graph.printNodes();
    cout << "Longest path: " << graph.longestPath() << endl;
}
