// Problem 648.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given the head to a singly linked list, where each node also has a “random” 
pointer that points to anywhere in the linked list, deep clone the list.*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node* random;

    Node(int val): value(val), next(nullptr), random(nullptr) {};
};

struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    Node* findNode(int value) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->value == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void setRandomPointer(int nodeValue, int randomValue) {
        Node* node = findNode(nodeValue);
        Node* randomNode = findNode(randomValue);

        if (node) {
            node->random = randomNode;
        }
    }

    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << "Data: " << temp->value << ", Node Pointer: " << temp;
            if (temp->random) {
                std::cout << ", Random: " << temp->random->value;
            }
            else {
                std::cout << ", Random: nullptr";
            }
            std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }


    void copyList(LinkedList& newList) {
        unordered_map<Node*, Node*> nodeMap;
        //LinkedList newList;

        Node* current = head;
        Node* newHead = nullptr;
        Node* newTail = nullptr;

        while (current != nullptr) {
            Node* newNode = new Node(current->value);
            if (newHead == nullptr) {
                newHead = newNode;
                newTail = newNode;
            }
            else {
                newTail->next = newNode;
                newTail = newNode;
            }
            nodeMap[current] = newNode; // Map original nodes to new nodes
            current = current->next;
        }

        // Second pass: set the random pointers
        current = head;
        Node* newCurrent = newHead;
        while (current != nullptr) {
            if (current->random != nullptr) {
                newCurrent->random = nodeMap[current->random];
            }
            current = current->next;
            newCurrent = newCurrent->next;
        }

        newList.head = newHead;
    }
};

int main()
{
    LinkedList list2;
    {
        LinkedList list;
        //LinkedList list2;
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        list.setRandomPointer(1, 3);
        list.setRandomPointer(2, 3);
        list.setRandomPointer(3, 5);
        list.setRandomPointer(4, 1);
        list.setRandomPointer(5, 1);
        list.printList();
        list.copyList(list2);
        list2.printList();
    }
    list2.printList();

}
