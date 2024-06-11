// Problem 598.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*You have n fair coins and you flip them all at the same time. Any that come up tails you set aside. 
The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?

Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.*/

#include <iostream>

using namespace std;

int getFlips(int input) {
    int times = 0;
    while (input > 1) {
        times++;
        input /= 2;
    }
    return times;
}

int main()
{
    int input;
    cout << "Enter number of coins:" << endl;
    cin >> input;
    cout << getFlips(input) << endl;
}
