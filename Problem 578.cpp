// problem #578.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Easy

Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

bool mapStrings(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    std::map<char, char> stringMap;
    for (int i = 0; i < s1.length(); i++) {
        if (stringMap.find(s1[i]) == stringMap.end()) {
            stringMap[s1[i]] = s2[i];
        }
        else if (s2[i] != stringMap[s1[i]]) {
            return false;
        }
    }
    
    return true;
}

int main()
{
    string s1 = "";
    string s2 = "";
    while (s1 != "exit") {
        cout << "Enter first string" << endl;
        getline(cin, s1);
        cout << "Enter second string" << endl;
        getline(cin, s2);
        if (mapStrings(s1, s2)) {
            cout << s1 << " maps to " << s2 << endl;
        }
        else {
            cout << s1 << " does not map to " << s2 << endl;
        }
    }
    return 0;
}
