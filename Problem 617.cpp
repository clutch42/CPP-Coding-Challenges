// Problem 617.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*The values of Roman numerals are as follows:

{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}
In addition, note that the Roman numeral system uses subtractive notation for numbers such as IV and XL.

For the input XIV, for instance, you should return 14.*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int convert(const unordered_map<char, int>& romanNumerals, const string& input) {
    int newNumber = 0;
    for (auto letter : input) {
        if (romanNumerals.find(letter) == romanNumerals.end()) {
            return 0;
        }
    }

    for (size_t i = 0; i < input.size(); i++) {
        if (input.size() >= 4 && i < input.size() - 3 && romanNumerals.at(input[i])== romanNumerals.at(input[i+1]) && romanNumerals.at(input[i]) == romanNumerals.at(input[i+2]) && romanNumerals.at(input[i]) == romanNumerals.at(input[i+3])) {
            return 0;
        }
        if (i < input.size() - 1 && romanNumerals.at(input[i]) < romanNumerals.at(input[i+1])) {
            newNumber += romanNumerals.at(input[i + 1]) - romanNumerals.at(input[i]);
            i++;
        }
        else {
            newNumber += romanNumerals.at(input[i]);
        }
    }
    return newNumber;
}

int main()
{
    unordered_map<char, int> romanNumerals = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
    string input;
    while (1) {
        cout << "Enter roman numeral: ";
        getline(cin, input);
        cout << "Numerical digit: ";
        cout << convert(romanNumerals, input) << endl;
    }
}
