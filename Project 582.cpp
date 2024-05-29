// Project 582.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Let X be a set of n intervals on the real line. We say that a set of points P "stabs" X if every interval in X contains at least one point in P. Compute the smallest set of points that stabs X.

For example, given the intervals [(1, 4), (4, 5), (7, 9), (9, 12)], you should return [4, 9]*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<double> stabPoints(vector<std::pair<double, double>> pairs) {
    vector<double> stab;

    sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;  // Ascending order for first element
    });

    double currStab = numeric_limits<double>::max();;
    

    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;

        if (p.first > currStab) {
            stab.push_back(currStab);
            currStab = p.second;
        }
        else {
            currStab = min(currStab, p.second);
        }
    }
    stab.push_back(currStab);


    return stab;
}

int main()
{
    vector<pair<double, double>> pairs;
    pairs.push_back(make_pair(7, 9));
    pairs.push_back(make_pair(1, 4));
    pairs.push_back(make_pair(4, 5));
    pairs.push_back(make_pair(9, 12));
    for (auto s : stabPoints(pairs)) {
        cout << s << " ";
    }
    cout << endl << endl;

    vector<pair<double, double>> pairs2;
    pairs2.push_back(make_pair(7.1, 9.2));
    pairs2.push_back(make_pair(1.3, 4.4));
    pairs2.push_back(make_pair(4.4, 5.5));
    pairs2.push_back(make_pair(9.2, 12.0));
    pairs2.push_back(make_pair(1.3, 5.4));
    for (auto s : stabPoints(pairs2)) {
        cout << s << " ";
    }
    cout << endl << endl;

    // Test Case 2
    vector<pair<double, double>> pairs1;
    pairs1.push_back(make_pair(0, 1));
    pairs1.push_back(make_pair(2, 3));
    pairs1.push_back(make_pair(4, 5));
    pairs1.push_back(make_pair(6, 7));
    pairs1.push_back(make_pair(8, 9));
    for (auto s : stabPoints(pairs1)) {
        cout << s << " ";
    }
    cout << endl << endl;

    // Test Case 3
    vector<pair<double, double>> pairs3;
    pairs3.push_back(make_pair(-2, -1));
    pairs3.push_back(make_pair(0, 2));
    pairs3.push_back(make_pair(3, 5));
    pairs3.push_back(make_pair(6, 8));
    pairs3.push_back(make_pair(9, 11));
    for (auto s : stabPoints(pairs3)) {
        cout << s << " ";
    }
    cout << endl << endl;

    // Test Case 4
    vector<pair<double, double>> pairs4;
    pairs4.push_back(make_pair(1, 3));
    pairs4.push_back(make_pair(2, 4));
    pairs4.push_back(make_pair(3, 5));
    pairs4.push_back(make_pair(4, 6));
    pairs4.push_back(make_pair(5, 7));
    for (auto s : stabPoints(pairs4)) {
        cout << s << " ";
    }
    cout << endl << endl;

    // Test Case 5
    vector<pair<double, double>> pairs5;
    pairs5.push_back(make_pair(0, 10));
    pairs5.push_back(make_pair(1, 9));
    pairs5.push_back(make_pair(2, 8));
    pairs5.push_back(make_pair(3, 7));
    pairs5.push_back(make_pair(4, 6));
    for (auto s : stabPoints(pairs5)) {
        cout << s << " ";
    }
    cout << endl << endl;
}
