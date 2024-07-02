// Problem 615.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*The stable marriage problem is defined as follows:

Suppose you have N men and N women, and each person has ranked their prospective opposite-sex partners in order of preference.

For example, if N = 3, the input could be something like this:

guy_preferences = {
    'andrew': ['caroline', 'abigail', 'betty'],
    'bill': ['caroline', 'betty', 'abigail'],
    'chester': ['betty', 'caroline', 'abigail'],
}

gal_preferences = {
    'abigail': ['andrew', 'bill', 'chester'],
    'betty': ['bill', 'andrew', 'chester'],
    'caroline': ['bill', 'chester', 'andrew']
}
Write an algorithm that pairs the men and women together in such a way that no two people of opposite sex would both rather be with each other than with their current partners.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<string, string> findPairs(unordered_map<string, vector<string>>& menPreferences, unordered_map<string, vector<string>>& womenPreferences) {
    queue<string> freeMen;
    unordered_map<string, int> engaged;
    unordered_map<string, string> married;
    for (auto m : menPreferences) {
        freeMen.push(m.first);
    }
    for (auto w : womenPreferences) {
        engaged[w.first] = -1;
    }
    while (!freeMen.empty()) {
        string man = freeMen.front();
        freeMen.pop();

        string woman = menPreferences[man][0];
        menPreferences[man].erase(menPreferences[man].begin());

        int currentEngagement = engaged[woman];

        int position = -1;
        for (int i = 0; i < womenPreferences[woman].size(); i++) {
            if (womenPreferences[woman][i] == man) {
                position = i;
                break;
            }
        }
        if (currentEngagement == -1 || position < currentEngagement) {
            engaged[woman] = position;
            if (currentEngagement != -1) {
                freeMen.push(married[woman]);
            }
            married[woman] = man;
        }
        else {
            freeMen.push(man);
        }
        
    }
    return married;
}

int main()
{
    unordered_map<string, vector<string>> menPreferences;
    menPreferences["andrew"] = { "caroline", "abigail", "betty" };
    menPreferences["bill"] = { "caroline", "betty", "abigail" };
    menPreferences["chester"] = { "betty", "caroline", "abigail" };

    unordered_map<string, vector<string>> womenPreferences;
    womenPreferences["abigail"] = { "andrew", "bill", "chester" };
    womenPreferences["betty"] = { "bill", "andrew", "chester" };
    womenPreferences["caroline"] = { "bill", "chester", "andrew" };

    unordered_map<string, string> result = findPairs(menPreferences, womenPreferences);
    for (auto r : result) {
        cout << r.second << " marries " << r.first << endl;
    }
    menPreferences["andrew"] = { "caroline", "abigail", "betty" };
    menPreferences["bill"] = { "caroline", "betty", "abigail" };
    menPreferences["chester"] = { "betty", "caroline", "abigail" };

    womenPreferences["abigail"] = { "andrew", "bill", "chester" };
    womenPreferences["betty"] = { "bill", "andrew", "chester" };
    womenPreferences["caroline"] = { "bill", "chester", "andrew" };

    result = findPairs(womenPreferences, menPreferences);
    for (auto r : result) {
        cout << r.second << " marries " << r.first << endl;
    }
}
