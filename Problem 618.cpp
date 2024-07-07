// Problem 618.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a list, sort it using this method: reverse(lst, i, j), which reverses lst from i to j.*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printList(const vector<T>& lst) {
    for (auto l : lst) {
        cout << l << " ";
    }
    cout << endl;
}

template <typename T>
void reverse(vector<T>& lst, int i, int j) {
    while (i < j) {
        T temp;
        temp = lst[i];
        lst[i] = lst[j];
        lst[j] = temp;
        i++;
        j--;
    }
}

template<typename T>
void sortList(vector<T>& lst) {
    for (size_t i = 0; i < lst.size()-1; i++) {
        for (size_t j = i + 1; j < lst.size(); j++) {
            if (lst[i] > lst[j]) {
                reverse(lst, i, j);
                printList(lst);
            }
        }
    }
}

int main()
{
    vector<int> lst = { 5,3,4,7,2,1,6 };
    sortList(lst);
    printList(lst);
    vector<char> lst2 = { 'F', 'B', 'G', 'A', 'C', 'E', 'D'};
    sortList(lst2);
    printList(lst2);
}
