// Problem 631.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*The skyline of a city is composed of several buildings of various widths and heights, possibly overlapping one another when viewed from a distance. We can represent the buildings using an array of (left, right, height) tuples, which tell us where on an imaginary x-axis a building begins and ends, and how tall it is. The skyline itself can be described by a list of (x, height) tuples, giving the locations at which the height visible to a distant observer changes, and each new height.

Given an array of buildings as described above, create a function that returns the skyline.

For example, suppose the input consists of the buildings [(0, 15, 3), (4, 11, 5), (19, 23, 4)]. In aggregate, these buildings would create a skyline that looks like the one below.

     ______  
    |      |        ___
 ___|      |___    |   | 
|   |   B  |   |   | C |
| A |      | A |   |   |
|   |      |   |   |   |
------------------------
As a result, your function should return [(0, 3), (4, 5), (11, 3), (15, 0), (19, 4), (23, 0)].*/

#include <iostream>
#include <tuple>
#include <vector>
#include <map>

using namespace std;

vector<pair<int, int>> findSkyLine(const vector<tuple<int, int, int>>& buildings) {
    vector<pair<int, int>> skyLine;
    map<int, int> heights;
    int min = INT_MAX;
    int max = INT_MIN;
    for (auto b : buildings) {
        if (get<0>(b) < min) {
            min = get<0>(b);
        }
        if (get<1>(b) > max) {
            max = get<1>(b);
        }
        for (int i = get<0>(b); i < get<1>(b); i++) {
            if (!heights[i]) {
                heights[i] = get<2>(b);
            }
            else {
                if (get<2>(b) > heights[i]) {
                    heights[i] = get<2>(b);
                }
            }

        }
    }
    skyLine.push_back(make_pair(min, heights[min]));
    for (int i = min+1; i <= max; i++) {
        if (!heights[i]) {
            heights[i] = 0;
        }
        if (heights[i - 1] != heights[i]) {
            skyLine.push_back(make_pair(i, heights[i]));
        }
    }


    return skyLine;
}

void printVectorPairs(vector<pair<int, int>> skyLine) {
    for (auto s : skyLine) {
        cout << "(" << s.first << ", " << s.second << ") ";
    }
    cout << endl;
}

int main()
{
    vector<tuple<int, int, int>> buildings = { make_tuple(0, 15, 3), make_tuple(4, 11, 5), make_tuple(19, 23, 4)};
    vector<pair<int, int>> skyLine = findSkyLine(buildings);
    printVectorPairs(skyLine);
}
