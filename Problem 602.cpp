// Problem 602.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Suppose you are given two lists of n points, one list p1, p2, ..., pn on the line y = 0 
and the other list q1, q2, ..., qn on the line y = 1. Imagine a set of n line segments connecting 
each point pi to qi. Write an algorithm to determine how many pairs of the line segments intersect.*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T>& list) {
    for (size_t i = 0; i < list.size() - 1; i++) {
        cout << list.at(i) << "\t";
    }
    cout << list.at(list.size() - 1) << endl;
}

int findIntersections(const vector<int>& list1, const vector<int>& list2) {
    int counter = 0;
    if (list1.size() != list2.size() || list1.size() == 0 || list1.size() == 1) {
        return counter;
    }
    for (size_t i = 0; i < list1.size() - 1; i++) {
        for (size_t j = i + 1; j < list1.size(); j++) {
            if (list1.at(i) < list1.at(j) && list2.at(i) > list2.at(j)) {
                counter++;
            }
            if (list1.at(i) > list1.at(j) && list2.at(i) < list2.at(j)) {
                counter++;
            }
        }
    }


    return counter;
}

int main()
{
    vector<int> list1 = { 0, 1, 2, 3, 4 };
    vector<int> list2 = { 1, 0, 4, 2, 3 };
    printVector(list1);
    printVector(list2);
    cout << findIntersections(list1, list2) << endl;

    list1 = { 1,2,3,4 };
    list2 = { 1,2,3,4 };
    printVector(list1);
    printVector(list2);
    cout << findIntersections(list1, list2) << endl;

    list1 = { 1,2 };
    list2 = { 2,1 };
    printVector(list1);
    printVector(list2);
    cout << findIntersections(list1, list2) << endl;

    list1 = { 1,3,5 };
    list2 = { 3,1,2 };
    printVector(list1);
    printVector(list2);
    cout << findIntersections(list1, list2) << endl;

    list1 = { 1,2,3,4 };
    list2 = { 4,3,2,1 };
    printVector(list1);
    printVector(list2);
    cout << findIntersections(list1, list2) << endl;
}
