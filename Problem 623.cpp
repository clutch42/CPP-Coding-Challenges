// Problem 623.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line. There should be at least one space between each word. Pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
    for (auto v : vec) {
        cout << v << endl;
    }
}

string mergeStrings(vector<string> words, const int& length) {
    int numChars = 0;
    int spaces = 0;
    string newString = "";
    if (words.size() == 1) {
        int spaces = length - words[0].size();
        newString = words[0];
        for (int i = 0; i < spaces / 2; i++) {
            newString = ' ' + newString + ' ';
        }
        if (spaces % 2 == 1) {
            newString = ' ' + newString;
        }
        return newString;
    }
    for (auto w : words) {
        numChars += w.length();
    }
    spaces = length - numChars;
    for (int i = 0; i < spaces; i++) {
        words[i % (words.size() - 1)] += ' ';
    }
    for (auto w : words) {
        newString += w;
    }
    return newString;
}

vector<string> justifySentence(const vector<string>& sentence, const int& length) {
    vector<vector<string>> newStringsVector;
    vector<string> strings;
    int charCount = 0;
    for (int i = 0; i < sentence.size(); i++) {
        int wordSize = sentence.at(i).length();
        if (strings.empty()) {
            strings.push_back(sentence[i]);
            charCount += wordSize;
            continue;
        }
        if (charCount + wordSize + 1 <= length) {
            strings.push_back(sentence[i]);
            charCount += wordSize+1;
        }
        else {
            newStringsVector.push_back(strings);
            strings.clear();
            charCount = 0;
            strings.push_back(sentence[i]);
            charCount += wordSize;
        }
    }
    newStringsVector.push_back(strings);
    string newString = "";
    strings.clear();
    for (auto n : newStringsVector) {
        newString = mergeStrings(n, length);
        strings.push_back(newString);
    }
    return strings;
}

int main()
{
    int lineLength = 16;
    vector<string> sentence = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
    vector<string> result = justifySentence(sentence, lineLength);
    printVector(result);
}
