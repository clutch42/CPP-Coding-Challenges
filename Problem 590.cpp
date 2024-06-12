// Problem 590.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields,
it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has
an add(element) which adds the element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and
dereference_pointer functions that converts between nodes and memory addresses.*/

#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

class XORLinkedList {
private:
    struct Node {
        string data;
        Node* both;

        Node(const string& d) : data(d), both(nullptr) {}
    };

    Node* head;
    Node* tail;

    static Node* XOR(Node* a, Node* b) {
        return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
    }
public:
    XORLinkedList() : head(nullptr), tail(nullptr) {}
    
    void add(const string& data) {
        Node* newNode = new Node(data);
        //newNode->both = tail;

        if (this->head == nullptr) {
            this->head = newNode;
        }
        else {
            this->tail->both = XOR(this->tail->both, newNode);
            newNode->both = this->tail;
        }
        this->tail = newNode;
    }

    void forward() {
        Node* current = this->head;
        Node* prev = nullptr;
        Node* next;

        while (current != nullptr) {
            cout << current->data << " ";
            next = XOR(prev, current->both);
            prev = current;
            current = next;
        }
        cout << endl;
    }

    void backward() {
        Node* current = this->tail;
        Node* prev;
        Node* next = nullptr;

        while (current != nullptr) {
            cout << current->data << " ";
            prev = XOR(next, current->both);
            next = current;
            current = prev;
        }
        cout << endl;
    }

    string get(int index) {
        Node* current = this->head;
        Node* prev = nullptr;
        Node* next;
        int count = 0;

        while (current != nullptr && count <= index) {
            if (count == index) {
                return current->data;
            }
            next = XOR(prev, current->both);
            prev = current;
            current = next;
            count++;
        }
        return "index not found";
    }

};

int main()
{
    XORLinkedList ll;
    ll.add("hello");
    ll.add("to");
    ll.add("you");
    ll.forward();
    ll.backward();
    cout << ll.get(0) << endl;
    cout << ll.get(2) << endl;
    cout << ll.get(1) << endl;
    cout << ll.get(3) << endl;
}
