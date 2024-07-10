// Problem 624.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid (i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.*/

#include <iostream>

using namespace std;

int unmatched(string par) {
    bool cont = true;
    while (cont && par.length() > 0) {
        cont = false;
        for (int i = 0; i < par.length() - 1; i++) {
            if (par[i] == '(' && par[i + 1] == ')') {
                cont = true;
                par = par.substr(0, i) + par.substr(i + 2, par.length() - i + 2);
                break;
            }
        }
    }
    return par.length();
}

int main()
{
    string par = "((())((())))()";
    cout << unmatched(par);
}
