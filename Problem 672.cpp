// Problem 672.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*You are given an array of arrays of integers, where each array corresponds to a row in a triangle of 
numbers. For example, [[1], [2, 3], [1, 5, 1]] represents the triangle:

  1
 2 3
1 5 1
We define a path in the triangle to start at the top and go down one row at a time to an adjacent value, 
eventually ending with an entry on the bottom row. For example, 1 -> 3 -> 5. The weight of the path is 
the sum of the entries.

Write a program that returns the weight of the maximum weight path.*/

#include <iostream>
#include <vector>

using namespace std;

int findPath(int level, int pos, const vector<vector<int>>& triangle) {
    if (level == triangle.size() - 1) {
        return triangle.at(level).at(pos);
    }
    int left = findPath(level + 1, pos, triangle);
    int right = findPath(level + 1, pos + 1, triangle);
    if (left > right) {
        return left + triangle.at(level).at(pos);
    }
    else {
        return right + triangle.at(level).at(pos);
    }
}

int findMaxPath(const vector<vector<int>>& triangle) {
    int maxPath = 0;
    
    maxPath = findPath(0, 0, triangle);

    return maxPath;
}

int main()
{
    vector<vector<int>> triangle1 = { {1} };
    vector<vector<int>> triangle2 = { {1}, {1,2} };
    vector<vector<int>> triangle3 = { {1}, {2,3}, {1,5,1} };
    vector<vector<int>> triangle4 = { {1}, {1,2}, {3,2,1}, {1,1,2,1} };
    cout << findMaxPath(triangle1) << endl;
    cout << findMaxPath(triangle2) << endl;
    cout << findMaxPath(triangle3) << endl;
    cout << findMaxPath(triangle4) << endl;
}
