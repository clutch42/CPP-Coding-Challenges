// Problem 647.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false, since we can't split it up into two subsets that add up to the same sum.*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool splitInTwoEqually(const vector<int>& setOfInts) {
    unordered_set<int> totals;
    int newSetTotal = 0;
    for (auto s : setOfInts) {
        newSetTotal += s;
    }
    if (newSetTotal % 2 != 0) {
        return false;
    }
    newSetTotal /= 2;
    totals.insert(0);
    for (auto s : setOfInts) {
        unordered_set<int> tempTotals = totals;
        for (auto t : totals) {
            if (t + s == newSetTotal) {
                cout << t + s << endl;
                return true;
            }
            else if (t + s < newSetTotal) {
                tempTotals.insert(t + s);
            }
        }
        totals = tempTotals;
    }


    return false;
}

int main()
{
    vector<int> setOfInts = { 15, 5, 20, 10, 35, 15, 10 };
    cout << splitInTwoEqually(setOfInts) << endl;
    setOfInts = { 15, 5, 20, 10, 35 };
    cout << splitInTwoEqually(setOfInts) << endl;
    setOfInts = { 1, 5, 20, 10, 35, 1 };
    cout << splitInTwoEqually(setOfInts) << endl;
}
