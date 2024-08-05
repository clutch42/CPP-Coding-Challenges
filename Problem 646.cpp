// Problem 646.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*A classroom consists of N students, whose friendships can be represented in an adjacency list. For example, 
the following descibes a situation where 0 is friends with 1 and 2, 3 is friends with 6, and so on.

{0: [1, 2],
 1: [0, 5],
 2: [0],
 3: [6],
 4: [],
 5: [1],
 6: [3]} 

Each student can be placed in a friend group, which can be defined as the transitive closure of that 
student's friendship relations. In other words, this is the smallest set such that no student in the 
group has any friends outside this group. For the example above, the friend groups would be {0, 1, 2, 5}, {3, 6}, {4}.

Given a friendship list such as the one above, determine the number of friend groups in the class.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(unordered_set<int>& visited, const unordered_map<int, vector<int>>& friendMap, int current) {
    visited.insert(current);
    for (auto each : friendMap.at(current)) {
        if (visited.find(each) == visited.end()) {
            dfs(visited, friendMap, each);
        }
    }

}

int getGroups(const unordered_map<int, vector<int>>& friendMap) {
    unordered_set<int> visited;
    int count = 0;
    for (const auto& f : friendMap) {
        int current = f.first;
        if (visited.find(current) == visited.end()) {
            count++;
            dfs(visited, friendMap, current);
        }
    }

    return count;
}

int main()
{
    unordered_map<int, vector<int>> friendMap = {
        {0, {1, 2}},
        {1, {0, 5}},
        {2, {0}},
        {3, {6}},
        {4, {}},
        {5, {1}},
        {6, {3}},
    };
    int groups = getGroups(friendMap);
    cout << "Number of groups: " << groups << endl;
}
