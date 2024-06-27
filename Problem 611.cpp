// Problem 611.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Create a data structure that performs all the following operations in O(1) time:

plus: Add a key with value 1. If the key already exists, increment its value by one.
minus: Decrement the value of a key. If the key's value is currently 1, remove it.
get_max: Return a key with the highest value.
get_min: Return a key with the lowest value.*/

#include <iostream>
#include <map>

using namespace std;

struct Node {
    int value;
    string key;
    Node* next;
    Node* prev;

    Node(string k, int v): key(k), value(v), next(nullptr), prev(nullptr) {}
};

struct DoubleLinkedList {
    Node* head;
    Node* tail;

    DoubleLinkedList() {
        head = new Node("", 0);
        tail = new Node("", 0);
        head->next = tail;
        tail->prev = head;
    }

    void addNodeAfter(Node* prevNode, Node* newNode) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void moveToCorrectPosition(Node* node) {
        // Disconnect node
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // Find correct position
        Node* current = head;
        while (current->next != tail && current->next->value < node->value) {
            current = current->next;
        }

        // Insert node
        addNodeAfter(current, node);
    }
};

struct DataStructure {
    DoubleLinkedList list;
    map<string, pair<int, Node*>> dataMap;
    
    void plus(const string& key) {
        if (dataMap.find(key) == dataMap.end()) {
            Node* node = new Node(key, 1);
            list.addNodeAfter(list.head, node);
            dataMap[key] = { 1, node };
        }
        else {
            Node* node = dataMap[key].second;
            node->value += 1;
            list.moveToCorrectPosition(node);
            dataMap[key].first = node->value;
        }
    }

    void minus(const string& key) {
        if (dataMap.find(key) == dataMap.end()) return;

        Node* node = dataMap[key].second;
        dataMap[key].first -= 1;
        node->value = dataMap[key].first;

        if (dataMap[key].first == 0) {
            list.deleteNode(node);
            dataMap.erase(key);
        }
        else {
            list.moveToCorrectPosition(node);
        }
    }

    string get_max() {
        if (list.tail->prev == list.head) return ""; // Check if list is empty
        return list.tail->prev->key; // Return the key associated with the maximum value
    }

    string get_min() {
        if (list.head->next == list.tail) return ""; // Check if list is empty
        return list.head->next->key; // Return the key associated with the maximum value
    }
};

int main()
{
    DataStructure ds;
    ds.plus("apple");
    ds.plus("banana");
    ds.plus("apple");
    ds.plus("apple");
    ds.plus("apple");
    std::cout << "Max: " << ds.get_max() << std::endl; 
    std::cout << "Min: " << ds.get_min() << std::endl; 
    ds.minus("apple");
    std::cout << "Max: " << ds.get_max() << std::endl; 
    std::cout << "Min: " << ds.get_min() << std::endl; 
    ds.minus("apple");
    std::cout << "Max: " << ds.get_max() << std::endl; 
    std::cout << "Min: " << ds.get_min() << std::endl; 
    ds.plus("banana");
    ds.plus("banana");
    std::cout << "Max: " << ds.get_max() << std::endl; 
    std::cout << "Min: " << ds.get_min() << std::endl; 
    return 0;
}
