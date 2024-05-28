// Project 583.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1
The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxCoins(vector<vector<int>> matrix, int rightPosition = 0, int lowerPosition = 0) {
    if (matrix.empty() || matrix.at(0).empty()) {
        return 0;
    }
    int rightBound = matrix.at(0).size() - 1;
    int lowerBound = matrix.size() - 1;
    
    if (rightPosition == rightBound && lowerPosition == lowerBound) {
        return matrix.at(lowerPosition).at(rightPosition);
    }

    int rightCoin = INT_MIN;
    int lowerCoin = INT_MIN;
    if (rightPosition < rightBound) {
        rightCoin = maxCoins(matrix, (rightPosition+1), lowerPosition);
    }
    if (lowerPosition < lowerBound)
        lowerCoin = maxCoins(matrix, rightPosition, lowerPosition+1);
    
    return matrix.at(lowerPosition).at(rightPosition) + max(rightCoin, lowerCoin);
}

int main()
{
    vector<vector<int>> matrix1 = {{0, 3, 1, 1},{2, 0, 0, 4},{1, 5, 3, 1}};
    vector<vector<int>> matrix2 = { {} };
    vector<vector<int>> matrix3 = { {0, 3, 1, 1},{2, 10, 10, 4},{1, 5, 3, 1} };
    vector<vector<int>> matrix4 = { {0, 3, 1, 1, 0},{2, 0, 0, 0, 4},{0, 1, 5, 3, 1},{0, 0, 0, 5, 3 } };
    vector<vector<int>> matrix5 = { {0, -3, -1, -1},{-2, 0, 0, -4},{-1, -5, -3, -1} };
    cout << "Example matrix: " << maxCoins(matrix1) << endl;
    cout << "Empty matrix: " << maxCoins(matrix2) << endl;
    cout << "Matrix 3: " << maxCoins(matrix3) << endl;
    cout << "Matrix 4: " << maxCoins(matrix4) << endl;
    cout << "Negative matrix: " << maxCoins(matrix5) << endl;
}
