// Problem 649.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a string, return the first recurring character in it, or null if there is no recurring character.

For example, given the string "acbbac", return "b". Given the string "abcdef", return null.*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

char getRepeatingChar(const string& input) {
    unordered_map<char, bool> numOfChars;
    for (auto i : input) {
        if (numOfChars[i]) {
            return i;
        }
        else {
            numOfChars[i] = true;
        }
    }

    return '\0';
}

int main()
{
    string input;
    while (1) {
        cout << "Enter String: ";
        getline(cin, input);
        char result = getRepeatingChar(input);
        cout << "First Repeating Character is: ";
        if (result != '\0') {
            cout << result << endl;
        }
        else {
            cout << "Null" << endl;
        }
    }
}
