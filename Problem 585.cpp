// Problem 585.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given an N by M matrix consisting only of 1's and 0's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
Return 4.*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//int findLargestRectangle(vector<vector<int>> matrix) {
//    if (matrix.empty() || matrix.at(0).empty()) {
//        return 0;
//    }
//    int area = 0;
//    int width = matrix.at(0).size();
//    int height = matrix.size();
//    for (int i = 0; i < height; i++) {
//        for (int j = 0; j < width; j++) {
//            if (matrix.at(i).at(j) == 1) {
//                int tempSum = 1;
//                for (int k = j + 1; k < width; k++) {
//                    if (matrix.at(i).at(k) == 1) {
//                        tempSum++;
//                    }
//                    else {
//                        break;
//                    }
//                }
//                int tempSum2 = tempSum;
//                for (int l = i + 1; l < height; l++) {
//                    bool matches = true;
//                    for (int m = j; m < j + tempSum; m++) {
//                        if (matrix.at(l).at(m) == 0) {
//                            matches = false;
//                        }
//                    }
//                    if (matches) {
//                        tempSum2 += tempSum;
//                    }
//                }
//                if (tempSum2 > area) {
//                    area = tempSum2;
//                }
//            }
//        }
//    }
//    return area;
//}

int findLargestRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                heights[j] = 0;
            }
            else {
                heights[j]++;
            }
        }
        int area = 0;
        vector<int> left(cols), right(cols, cols);

        stack<int> s;
        for (int j = 0; j < cols; ++j) {
            while (!s.empty() && heights[s.top()] >= heights[j]) {
                right[s.top()] = j;
                s.pop();
            }
            left[j] = (s.empty() ? -1 : s.top());
            s.push(j);
        }

        for (int j = 0; j < cols; ++j) {
            area = max(area, heights[j] * (right[j] - left[j] - 1));
        }
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> matrixa = { {1,0,0,0},{1,0,1,1},{1,0,1,1},{0,1,0,0} };
    vector<vector<int>> matrixb = { {} };
    vector<vector<int>> matrixc = { {1, 1, 0, 1} };
    cout << "Example: " << findLargestRectangle(matrixa) << endl;
    cout << "Empty: " << findLargestRectangle(matrixb) << endl;
    cout << "One line: " << findLargestRectangle(matrixc) << endl;

    // Test cases
    vector<vector<int>> matrix1 = { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} };
    vector<vector<int>> matrix2 = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    vector<vector<int>> matrix3 = { {1, 1, 0, 1, 1} };
    vector<vector<int>> matrix4 = { {1} };
    vector<vector<int>> matrix5 = { {} };
    vector<vector<int>> matrix6 = { {1, 0, 1}, {1, 1, 1}, {1, 1, 0} };
    vector<vector<int>> matrix7 = { {1, 0, 1, 0}, {1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 1, 1} };
    vector<vector<int>> matrix8 = {
        {1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1}
    };

    // Output test case results
    cout << "Test Case 1: " << findLargestRectangle(matrix1) << endl;
    cout << "Test Case 2: " << findLargestRectangle(matrix2) << endl;
    cout << "Test Case 3: " << findLargestRectangle(matrix3) << endl;
    cout << "Test Case 4: " << findLargestRectangle(matrix4) << endl;
    cout << "Test Case 5: " << findLargestRectangle(matrix5) << endl;
    cout << "Test Case 6: " << findLargestRectangle(matrix6) << endl;
    cout << "Test Case 7: " << findLargestRectangle(matrix7) << endl;
    cout << "Test Case 8: " << findLargestRectangle(matrix8) << endl;

}

