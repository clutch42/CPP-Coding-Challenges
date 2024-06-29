// Problem 607.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*There are M people sitting in a row of N seats, where M < N. Your task is to redistribute people such that
there are no gaps between any of them, while keeping overall movement to a minimum.

For example, suppose you are faced with an input of [0, 1, 1, 0, 1, 0, 0, 0, 1], where 0 represents an empty 
seat and 1 represents a person. In this case, one solution would be to place the person on the right in the 
fourth seat. We can consider the cost of a solution to be the sum of the absolute distance each person must 
move, so that the cost here would be five.

Given an input such as the one above, return the lowest possible cost of moving people to remove all gaps.*/

#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<bool> vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

int numOfMoves(int start, int end, vector<bool> vec) {
    vector<bool> newVec(vec.size(), 0);
    for (size_t i = start; i <= end; i++) {
        newVec.at(i) = 1;
    }
    printVec(vec);
    printVec(newVec);
    int count = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if (i < start && vec.at(i) == 1) {
            for (size_t j = start; j <= end; j++) {
                if (vec.at(j) == 0) {
                    count += j - i;
                    vec.at(i) = 0;
                    vec.at(j) = 1;
                    break;
                }
            }
        }
        if (i > end && vec.at(i) == 1) {
            for (size_t j = start; j <= end; j++) {
                if (vec.at(j) == 0) {
                    count += i - j;
                    vec.at(i) = 0;
                    vec.at(j) = 1;
                    break;
                }
            }
        }
    }
    cout << count << endl;
    return count;
}

int leastMoves(vector<bool> row) {
    int count = 0;
    for (auto r : row) {
        if (r == 1) {
            count++;
        }
    }
    int least = INT_MAX;
    for (size_t i = 0; i < row.size() - count+1; i++) {
        int tempCount = numOfMoves(i, i + count - 1, row);
        if (tempCount < least) {
            least = tempCount;
        }
    }
    return least;
}

int main()
{
    vector<bool> row = { 0, 1, 1, 0, 1, 0, 0, 0, 1 };
    cout << leastMoves(row) << endl;
}
