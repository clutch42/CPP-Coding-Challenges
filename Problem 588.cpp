// Problem 588.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*You have a large array with most of the elements as zero.

Use a more space-efficient data structure, SparseArray, that implements the same interface:

init(arr, size): initialize with the original large array and size.
set(i, val): updates index at i with val.
get(i): gets the value at index i.*/

#include <iostream>
#include <unordered_map>

using namespace std;

class SparseArray {
private:
    unordered_map<int, int> newArray;
    int original_size;
public:
    SparseArray() : original_size(0) {}

    void init(int arr[], int size) {
        original_size = size;
        for (int i = 0; i < original_size; i++) {
            if (arr[i] != 0) {
                newArray[i] = arr[i];
            }
        }
    }

    void set(int i, int val) {
        if (val == 0) {
            newArray.erase(i);
        }
        else {
            newArray[i] = val;
        }
    }

    int get(int i) {
        if (!newArray[i]) {
            return 0;
        }
        else {
            return newArray[i];
        }
    }

    void printMap() {
        for (auto m : newArray) {
            cout << "key: " << m.first << ", value: " << m.second << endl;
        }
    }
};

int main()
{
    SparseArray sparseArray;
    int largeArray[10] = { 0,0,0,0,1,0,1,0,1,0 }; // Large array with mostly zeros
    sparseArray.init(largeArray, 10);
    sparseArray.printMap();

    sparseArray.set(4, 10);
    sparseArray.set(6, 0);
    sparseArray.printMap();

    // Test Case 2
    SparseArray sparseArray2;
    int largeArray2[10] = { 0 }; // Large array with mostly zeros
    sparseArray2.init(largeArray2, 10);
    sparseArray2.printMap();

    sparseArray2.set(0, 100);
    sparseArray2.set(9, 200);
    sparseArray2.printMap();
    sparseArray2.set(9, 201);
    sparseArray2.set(0, 0);
    sparseArray2.printMap();

    return 0;
}

