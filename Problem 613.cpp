// Problem 613.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map. If the key already exists, overwrite the value.
sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.
For example, you should be able to run the following code:

mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5*/

#include <iostream>
#include <unordered_map>

using namespace std;

class PrefixMapSum {
    unordered_map<string, int> map;
public:
    PrefixMapSum() {}
    void insert(string key, int value) {
        map[key] = value;
    }

    int sum(string prefix) {
        int size = prefix.length();
        int total = 0;
        for (auto m : map) {
            bool isPrefix = false;
            for (size_t i = 0; i < size; i++) {
                if (m.first.length()>=size && m.first[i] == prefix[i]) {
                    isPrefix = true;
                }
                else {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) {
                total += m.second;
            }
        }
        return total;
    }

    void printMap() {
        for (auto m : map) {
            cout << "Key: " << m.first << " Value: " << m.second << endl;
        }
    }
};

int main()
{
    PrefixMapSum prefixMap;
    prefixMap.insert("hey", 7);
    prefixMap.insert("hepo", 3);
    prefixMap.insert("heyo", 4);
    prefixMap.insert("hey", 2);
    prefixMap.printMap();
    cout << "Sum of hey: " << prefixMap.sum("hey") << endl;
    cout << "Sum of he: " << prefixMap.sum("he") << endl;
    cout << "Sum of heyo: " << prefixMap.sum("heyo") << endl;
}
