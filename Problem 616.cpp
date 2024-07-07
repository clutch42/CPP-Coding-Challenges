// Problem 616.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*A cryptarithmetic puzzle is a mathematical game where the digits of some numbers are represented by letters. Each letter represents a unique digit.

For example, a puzzle of the form:

  SEND
+ MORE
--------
 MONEY
may have the solution:

{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O', 0, 'R': 8, 'Y': 2}
Given a three-word puzzle like the one above, create an algorithm that finds a solution.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>


using namespace std;

int getNumFromWord(const vector<pair<char, int>>& solution, const string& word) {
    int number = 0;
    for (char c : word) {
        for (const auto& pair : solution) {
            if (pair.first == c) {
                number = number * 10 + pair.second;  // Multiply by 10 and add the current digit
                break;
            }
        }
    }
    return number;
}

void printSolution(const vector<pair<char, int>>& solution) {
    for (auto s : solution) {
        cout << s.first << ": " << s.second << " ";
    }
    cout << endl;
}

vector<pair<char, int>> getSolution(const string& word1, const string& word2, const string& equals) {
    vector<int> permutation = { 0,1,2,3,4,5,6,7,8,9 };
    unordered_set<char> includedLetters;
    vector<pair<char, int>> solution;
    for (auto w : word1) {
        includedLetters.insert(w);
    }
    for (auto w : word2) {
        includedLetters.insert(w);
    }
    for (auto w : equals) {
        includedLetters.insert(w);
    }
    if (includedLetters.size() > 10) {
        return {};
    }

    unordered_set<char> firstLetters;
    firstLetters.insert(word1[0]);
    firstLetters.insert(word2[0]);
    firstLetters.insert(equals[0]);


    do {
        int j = 0;
        solution.clear();

        for (auto i : includedLetters) {
            if (permutation[j] == 0 && firstLetters.count(i) > 0) {
                solution.clear();
                break;
            }
            solution.push_back({ i, permutation[j] });
            j++;
        }
        if (!solution.empty() && getNumFromWord(solution, word1) + getNumFromWord(solution, word2) == getNumFromWord(solution, equals)) {
            return solution;
        }

    } while (next_permutation(permutation.begin(), permutation.end()));

    return{};
}

int main()
{
    string word1 = "HERE";
    string word2 = "SHE";
    string equals = "COMES";

    vector<pair<char, int>> result = getSolution(word1, word2, equals);
    printSolution(result);
}

