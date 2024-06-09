// Problem 597.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given an array of integers, determine whether it contains a Pythagorean triplet. 
Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> findPythagorean(const vector<int>& input) {
    vector<int> sorted = input;
    vector<tuple<int, int, int>> output;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < sorted.size()-2; i++) {
        for (int j = i + 1; j < sorted.size() - 1; j++) {
            for (int k = j + 1; k < sorted.size(); k++) {
                if (sorted.at(i) * sorted.at(i) + sorted.at(j) * sorted.at(j) == sorted.at(k) * sorted.at(k) && sorted.at(i) > 0 && sorted.at(j) > 0 && sorted.at(k) > 0) {
                     output.push_back(make_tuple(sorted.at(i), sorted.at(j), sorted.at(k)));
                }
            }
        }
    }
    if (output.size() == 0) {
        output.push_back(make_tuple(0, 0, 0));
    }
    return output;
}

int main()
{
    vector<int> intArray = { 1, 2, 3 };
    vector< tuple<int, int, int>> answer = findPythagorean(intArray);
    cout << "Pythagorean Triplets:" << endl;
    for (auto a : answer) {
        cout << "(" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")" << endl;
    }
}
