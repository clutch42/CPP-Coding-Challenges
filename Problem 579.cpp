// Problem 579.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.

On the ith jump, you may move exactly i places to the left or right.

Find a path with the fewest number of jumps required to get from 0 to N.*/

#include <iostream>
#include <map>

using namespace std;

map<int, int> lowestSums;

int findJumpNum(const int& numToFind) {
    if (numToFind == 0) {
        return 0;
    }
    map<int, int> oldMap;
    oldMap[0] = 0;
    int tempValue = 0;
    while (1) {
        tempValue++;
        map<int, int> newMap;
        for (const auto& value : oldMap) {
            int posValue = value.first + tempValue;
            int negValue = value.first - tempValue;
            if (negValue < 0) {
                negValue = -negValue;
            }
            if (posValue == numToFind || negValue == numToFind) {
                return tempValue;
            }
            else {
                newMap[posValue] = tempValue;
                newMap[negValue] = tempValue;
            }
        }
        oldMap = newMap;
    }
    return -1;
}

int main()
{
    int numToFind;
    cout << "Enter number to find.\n";
    cin >> numToFind;
    if (numToFind < 0) {
        numToFind = -numToFind;
    }
    cout << findJumpNum(numToFind) << endl;
}
