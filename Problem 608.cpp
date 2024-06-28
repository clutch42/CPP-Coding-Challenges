// Problem 608.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a start word, an end word, and a dictionary of valid words, find the shortest transformation sequence from start to end such that only one letter is changed at each step of the sequence, and each transformed word exists in the dictionary. If there is no possible transformation, return null. Each word in the dictionary have the same length as start and end and is lowercase.

For example, given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"}, return ["dog", "dot", "dat", "cat"].

Given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"}, return null as there is no possible transformation from dog to cat.*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool oneLetterDifference(const string& word1, const string& word2) {
    int count = 0;
    for (size_t i = 0; i < word1.size(); i++) {
        if (word1[i] != word2[i]) {
            count++;
        }
    }
    return count == 1;
}

vector<string> findTransformation(const string& start, const string& end, unordered_set<string>& dict) {
    vector<string> result;
    if (start == end) {
        result.push_back(start);
        return result;
    }

    queue<vector<string>> paths;
    paths.push({ start });
    unordered_set<string> visited;
    visited.insert(start);

    while (!paths.empty()) {
        int size = paths.size();
        unordered_set<string> localVisited;
        for (int i = 0; i < size; i++) {
            vector<string> path = paths.front();
            paths.pop();
            string lastWord = path.back();

            for (auto it = dict.begin(); it != dict.end();) {
                if (oneLetterDifference(lastWord, *it)) {
                    vector<string> newPath = path;
                    newPath.push_back(*it);
                    if (*it == end) {
                        return newPath;
                    }
                    paths.push(newPath);
                    localVisited.insert(*it);
                    it = dict.erase(it);
                }
                else {
                    it++;
                }
            }
        }
        for (const string& word : localVisited) {
            visited.insert(word);
        }
    }

    return {};
}

int main()
{
    string start = "dog";
    string end = "cat";
    unordered_set<string> dict = { "dot", "dop", "dat", "cat"};
    vector<string> order = findTransformation(start, end, dict);
    for (auto o : order) {
        cout << o << endl;
    }

}
