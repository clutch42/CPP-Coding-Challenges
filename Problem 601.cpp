// Problem 601.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*The sequence [0, 1, ..., N] has been jumbled, and the only clue you have for its order is an array 
representing whether each number is larger or smaller than the last. Given this information, reconstruct 
an array that is consistent with it. For example, given [None, +, +, -, +], you could return [1, 2, 3, 0, 4].*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void outputVec(const vector<T>& input) {
    for (size_t i = 0; i < input.size() - 1; i++) {
        cout << input.at(i) << ", ";
    }
    cout << input.at(input.size()-1) << endl;
}

vector<int> findSequence(const vector<string>& input) {
    vector<int> newSequence(input.size());
    int numberOfElements = input.size();
    int numberOfMinus = 0;
    for (auto i : input) {
        if (i == "-") {
            numberOfMinus++;
        }
    }
    int nextPlus = numberOfMinus;
    int nextMinus = 0;
    for (size_t i = 0; i < input.size(); i++) {
        if (input.at(i) != "-") {
            newSequence.at(i) = nextPlus;
            nextPlus++;
        }
        else {
            newSequence.at(i) = nextMinus;
            nextMinus++;
        }
    }
    return newSequence;
}

int main()
{
    vector<string> input = { "none", "+", "+", "-", "+" };
    vector<int> sequence = findSequence(input);
    outputVec(input);
    outputVec(sequence);

    input = { "none", "+", "+", "-", "+", "+", "-", "-", "+"};
    sequence = findSequence(input);
    outputVec(input);
    outputVec(sequence);
}
