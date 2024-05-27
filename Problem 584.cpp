// Problem 584.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". Given "aaab", return None.*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

string rearrangeString(string input) {
    map<char, int> stringChars;
    for (char c : input) {
        if (stringChars[c]) {
            stringChars[c]++;
        }
        else {
            stringChars[c] = 1;
        }
    }


    int i = 0;
    string newString = input;
    while (!stringChars.empty()) {

        //for (const auto& pair : stringChars) {
        //    cout << pair.first << ": " << pair.second << endl;
        //}

        char maxChar = '\0';
        int maxValue = numeric_limits<int>::min();
        for (const auto& entry : stringChars) {
            if (entry.second > maxValue) {
                maxValue = entry.second;
                maxChar = entry.first;
            }
        }

        if (maxValue > ((input.length() + 1) / 2)) {
            return "none";
        }
        for (int j = 0; j < maxValue; j++) {
            if (i >= input.length()) {
                i = 1;
            }
            if (i < input.length()) {
                newString[i] = maxChar;
                i = i+2;
            }
        }
        stringChars.erase(maxChar);

    }

    return newString;
}

int main()
{
    string input;
    cout << "Enter string:" << endl;
    cin >> input;
    cout << rearrangeString(input) << endl;
}
