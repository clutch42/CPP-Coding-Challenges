// Problem 605.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*In academia, the h-index is a metric used to calculate the impact of a researcher's papers. It is calculated as follows:

A researcher has index h if at least h of her N papers have h citations each. If there are multiple h satisfying this formula, the maximum is chosen.

For example, suppose N = 5, and the respective citations of each paper are [4, 3, 0, 1, 5]. Then the h-index would be 3, since the researcher has 3 papers with at least 3 citations.

Given a list of paper citations of a researcher, calculate their h-index.*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int findHIndex(const vector<int>& scores) {
    int score = 0;
    int tempCount = 0;
    int maxCite = 0;
    map<int, int> scoreMap;
    for (auto s : scores) {
        scoreMap[s]++;
        if (s > maxCite) {
            maxCite = s;
        }
    }
    for (int i = 0; i <= maxCite; i++) {
        if (scoreMap.find(i) == scoreMap.end()) {
            scoreMap[i] = 0;
        }
    }
    for (auto it = scoreMap.rbegin(); it != scoreMap.rend(); ++it) {
         tempCount += it->second ;
         if (tempCount >=  it->first) {
             score = it->first;
             break;
         }
    }
    for (auto s : scoreMap) {
        cout << s.first << " = " << s.second << endl;
    }
    return score;
}

int main()
{
    vector<int> paperScores = { 0, 3, 6, 1, 7, 8, 9, 10 };
    cout << findHIndex(paperScores) << endl;
}
