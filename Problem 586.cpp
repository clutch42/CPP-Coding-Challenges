// Problem 586.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*You are given a list of (website, user) pairs that represent users visiting websites. Come up with a program that identifies the top k pairs of websites with the greatest similarity.

For example, suppose k = 1, and the list of tuples is:

[('a', 1), ('a', 3), ('a', 5),
 ('b', 2), ('b', 6),
 ('c', 1), ('c', 2), ('c', 3), ('c', 4), ('c', 5)
 ('d', 4), ('d', 5), ('d', 6), ('d', 7),
 ('e', 1), ('e', 3), ('e': 5), ('e', 6)]
Then a reasonable similarity metric would most likely conclude that a and e are the most similar, so your program should return [('a', 'e')].*/

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function to calculate Jaccard similarity
double jaccard_similarity(const unordered_set<int>& set1, const unordered_set<int>& set2) {
    unordered_set<int> intersection;
    unordered_set<int> union_set = set1;

    for (const int& user : set2) {
        union_set.insert(user);
        if (set1.find(user) != set1.end()) {
            intersection.insert(user);
        }
    }

    if (union_set.size() == 0) return 0.0;
    return (double)intersection.size() / union_set.size();
}

vector<tuple<char, char, double>> similarityCheck(const vector<pair<char, int>>& visitList, const int& amount) {

    for (auto l : visitList) {
        cout << "(" << l.first << ", " << l.second << ") ";
    }
    cout << endl;

    // Step 1: Create a map of websites to their user sets
    unordered_map<char, unordered_set<int>> website_users;
    for (const auto& visit : visitList) {
        website_users[visit.first].insert(visit.second);
    }

    // Step 2: Calculate pairwise Jaccard similarity
    vector<tuple<char, char, double>> similarities;
    vector<char> websites;
    for (const auto& user : website_users) {
        websites.push_back(user.first);
    }

    for (size_t i = 0; i < websites.size(); ++i) {
        for (size_t j = i + 1; j < websites.size(); ++j) {
            double similarity = jaccard_similarity(website_users[websites[i]], website_users[websites[j]]);
            similarities.push_back(make_tuple(websites[i], websites[j], similarity));
        }
    }

    // Step 3: Sort the similarities in descending order
    sort(similarities.begin(), similarities.end(), [](const auto& a, const auto& b) {
        return get<2>(a) > get<2>(b);
    });

    vector<tuple<char, char, double>> returnList;
    for (int i = 0; i < amount && i < similarities.size(); ++i) {
        returnList.push_back(similarities.at(i));
    }

    return returnList;
}

int main()
{

    vector<pair<char, int>> list1 = { 
        {'a', 1}, {'a', 3}, {'a', 5},
        {'b', 2}, {'b', 6},
        {'c', 1}, {'c', 2}, {'c', 3}, {'c', 4}, {'c', 5},
        {'d', 4}, {'d', 5}, {'d', 6}, {'d', 7},
        {'e', 1}, {'e', 3}, {'e', 5}, {'e', 6}
    };
    vector<tuple<char, char, double>> return1 = similarityCheck(list1, 100);
    for (auto r : return1) {
        cout << get<0>(r) << " and " << get<1>(r) << " are a " << get<2>(r) << " match." << endl;
    }
}
