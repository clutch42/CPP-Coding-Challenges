// Problem 592.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
*/

#include <iostream>
#include <vector>

using namespace std;

void changeToZeros(vector<vector<bool>>& islandMap, int i, int j) {
    if (i < 0 || j < 0 || i >= islandMap.size() || j >= islandMap.at(0).size() || islandMap.at(i).at(j) == 0) {
        return;
    }
    islandMap.at(i).at(j) = 0;
    changeToZeros(islandMap, i+1, j+1);
    changeToZeros(islandMap, i+1, j-1);
    changeToZeros(islandMap, i+1, j);
    changeToZeros(islandMap, i-1, j+1);
    changeToZeros(islandMap, i-1, j-1);
    changeToZeros(islandMap, i-1, j);
    changeToZeros(islandMap, i, j+1);
    changeToZeros(islandMap, i, j-1);
}

int getIslandNumber(vector<vector<bool>>& islandMap) {
    int count = 0;
    for (int i = 0; i < islandMap.size(); i++) {
        for (int j = 0; j < islandMap.at(0).size(); j++) {
            if (islandMap.at(i).at(j) == 1) {
                changeToZeros(islandMap, i, j);
                count++;
            }
            
        }

    }

    return count;
}

void printIsland(const vector<vector<bool>>& islandMap) {
    for (auto row : islandMap) {
        for (auto column : row) {
            cout << column << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<bool>> islandMap = {
        {1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {1, 1, 0, 0, 1}
    };
    printIsland(islandMap);
    cout << "There are " << getIslandNumber(islandMap) << " islands." << endl;

    islandMap = {
        {1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {1, 1, 0, 0, 1}
    };
    printIsland(islandMap);
    cout << "There are " << getIslandNumber(islandMap) << " islands." << endl;

    islandMap = {
        {1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {1, 1, 0, 0, 1}
    };
    printIsland(islandMap);
    cout << "There are " << getIslandNumber(islandMap) << " islands." << endl;

    islandMap = {
        {1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1}
    };
    printIsland(islandMap);
    cout << "There are " << getIslandNumber(islandMap) << " islands." << endl;
}

