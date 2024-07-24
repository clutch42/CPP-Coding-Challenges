// Problem 637.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVectorPairs(const vector<pair<int, int>>& pairs) {
    for (auto p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

void sortVector(vector<pair<int, int>>& original) {
    sort(original.begin(), original.end());
}

vector<pair<int, int>> condense(vector<pair<int, int>> original) {
    if (original.size() < 2) {
        return original;
    }
    sortVector(original);
    int index = 0;
    while (index < original.size()-1) {
        if (original[index].second >= original[index + 1].first) {
            if (original[index].second < original[index + 1].second) {
                original[index].second = original[index + 1].second;
            }
            original.erase(original.begin() + index + 1);
        }
        else {
            index++;
        }
    }

    return original;
}

int main()
{
    vector<pair<int, int>> original = { make_pair(1, 3), make_pair(5, 8), make_pair(4, 10), make_pair(20, 25) };
    printVectorPairs(original);
    vector<pair<int, int>> newVector = condense(original);
    printVectorPairs(newVector);
}
