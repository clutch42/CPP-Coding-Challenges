// Problem 610.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Implement division of two positive integers without using the division, multiplication, 
or modulus operators. Return the quotient as an integer, ignoring the remainder.*/

#include <iostream>

using namespace std;

int divide(const int& num1, const int& num2) {
    if (num2 == 0) {
        return -1;
    }
    int count = 0;
    int temp = num1;
    while (temp >= num2) {
        temp -= num2;
        count++;
    }
    return count;
}

int main()
{
    while (1) {
        int num1, num2;
        cout << "Enter numbers" << endl;
        cin >> num1;
        cin >> num2;

        cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
    }
}
