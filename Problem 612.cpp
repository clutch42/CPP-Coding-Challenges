// Problem 612.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8), return 1 as the last interval can be removed and the first two won't overlap.

The intervals are not necessarily sorted in any order.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) return 0;

    // Sort intervals based on their end times
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        });

    int count = 0;
    int end = intervals[0].second;

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first < end) {
            // Overlapping interval, increment count
            ++count;
        }
        else {
            // Non-overlapping interval, update end
            end = intervals[i].second;
        }
    }

    return count;
}

int main() {
    vector<pair<int, int>> intervals = { {7, 9}, {2, 4}, {5, 8} };
    cout << "Minimum number of intervals to remove: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}
