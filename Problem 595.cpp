// Problem 595.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*The number 6174 is known as Kaprekar's contant, after the mathematician who discovered an associated property: for all four-digit numbers with at least two distinct digits, repeatedly applying a simple procedure eventually results in this value. The procedure is as follows:

For a given input x, create two new numbers that consist of the digits in x in ascending and descending order.
Subtract the smaller number from the larger number.
For example, this algorithm terminates in three steps when starting from 1234:

4321 - 1234 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174
Write a function that returns how many steps this will take for a given input N.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validateInput(const int& input) {
    vector<int> cantUse = { 1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999 };
    if (input < 1000 || input > 9999) {
        cout << "Must be between 1000 and 9999" << endl;
        return false;
    }
    for (auto c : cantUse) {
        if (input == c) {
            cout << "Need 2 distinct digits." << endl;
            return false;
        }
    }
    return true;
}

vector<int> getDigits(const int& input) {
    vector<int> intVector;
    int tempNum = input;
    for (int i = 0; i < 4; i++) {
        int digit = tempNum % 10;
        intVector.push_back(digit);
        tempNum /= 10;
    }
    /*while (tempNum > 0) {
        int digit = tempNum % 10;
        intVector.push_back(digit);
        tempNum /= 10;
    }*/
    return intVector;
}

int maxDigit(const vector<int>& input) {
    vector<int> sortMax = input;
    sort(sortMax.begin(), sortMax.end());
    int tempTotal = 0;
    int tempTimesTen = 1;
    for (int i = 0; i < sortMax.size(); i++) {
        tempTotal += tempTimesTen * sortMax.at(i);
        tempTimesTen *= 10;
    }
    return tempTotal;
}

int minDigit(const vector<int>& input) {
    vector<int> sortMax = input;
    sort(sortMax.begin(), sortMax.end(), ::greater<int>());
    int tempTotal = 0;
    int tempTimesTen = 1;
    for (int i = 0; i < sortMax.size(); i++) {
        tempTotal += tempTimesTen * sortMax.at(i);
        tempTimesTen *= 10;
    }
    return tempTotal;
}

int Kaprekars(const int& input) {
    const int KaprekarsConstant = 6174;
    int nextNumber = input;
    int iterator = 0;
    if (input == KaprekarsConstant) {
        return 0;
    }
    while (nextNumber != KaprekarsConstant) {
        nextNumber = maxDigit(getDigits(nextNumber)) - minDigit(getDigits(nextNumber));
        cout << "Next Number: " << nextNumber << endl;
        iterator++;
    }

    return iterator;
}

int main()
{
    int input;
    vector<int> inputDigits;
    cout << "Enter a 4 digit number with at least 2 distinct digits." << endl;
    cin >> input;
    if (!validateInput(input)) {
        return 0;
    }
    cout << Kaprekars(input) << endl;
}
