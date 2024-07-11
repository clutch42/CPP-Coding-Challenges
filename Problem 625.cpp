// Problem 625.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.*/

#include <iostream>

using namespace std;

string convertToBinary(int num) {
    if (num == 0) {
        return "0";
    }
    string bin;
    while (num > 0) {
        bin = (num % 2 == 0 ? "0" : "1") + bin;
        num /= 2;
    }
    cout << bin << endl;
    return bin;
}

int numOfOnesInRow(string binNum) {
    int maxOnes = 0;
    int index = 0;
    int tempMax = 0;
    while (index < binNum.length()) {
        if (binNum[index] == '1') {
            tempMax++;
            index++;
            if (tempMax > maxOnes) {
                maxOnes = tempMax;
            }
        } else {
            tempMax = 0;
            index++;
        }
    }
    return maxOnes;
}

int onesInARow(int num) {
    string binNum;
    binNum = convertToBinary(num);
    return numOfOnesInRow(binNum);
}

int main()
{
    while (1) {
        int num;
        int result;
        cout << "Enter number: ";
        cin >> num;
        result = onesInARow(num);
        cout << result << endl;
    }
}
