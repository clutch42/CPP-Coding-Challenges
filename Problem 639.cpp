// Problem 639.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could represent. You can assume each valid number in the mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

void getPossibleString(vector<string>& combos, const unordered_map<char, vector<char>>& telephoneNumbers, string input, string prev = "") {
    if (input.length() == 0) {
        combos.push_back(prev);
        return;
    }
    vector<char> possibleLetters;
    auto it = telephoneNumbers.find(input[0]);
    if (it != telephoneNumbers.end()) {
        possibleLetters = telephoneNumbers.at(input[0]);
    } else {
        possibleLetters = { input[0] };
    }
    for (auto p : possibleLetters) {
        getPossibleString(combos, telephoneNumbers, input.substr(1), prev + p);
    }
}

int main()
{
    unordered_map<char, vector<char>> telephoneNumbers = {
        {'2', {'a', 'b', 'c'} },
        {'3', {'d', 'e', 'f'} },
        {'4', {'g', 'h', 'i'} },
        {'5', {'j', 'k', 'l'} },
        {'6', {'m', 'n', 'o'} },
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'} },
        {'9', {'w', 'x', 'y', 'z'}}
    };
    string input;
    cout << "Enter string: ";
    getline(cin, input);

    vector<string> results;
    getPossibleString(results, telephoneNumbers, input);
    for (auto r : results) {
        cout << r << endl;
    }
    cout << "Number of results: " << results.size() << endl;
}
