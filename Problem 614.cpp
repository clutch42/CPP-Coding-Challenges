// Problem 614.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*A network consists of nodes labeled 0 to N. You are given a list of edges (a, b, t), describing the time t 
it takes for a message to be sent from node a to node b. Whenever a node receives a message, it immediately 
passes the message on to a neighboring node, if possible.

Assuming all nodes are connected, determine how long it will take for every node to receive a message that begins at node 0.

For example, given N = 5, and the following edges:

edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
You should return 9, because propagating the message from 0 -> 2 -> 3 -> 4 will take that much time.*/

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

int minForAllNodes(const vector<tuple<int, int, int>>& edges, const int& nodes) {
    int longest = 0;
    vector<int> lengths(nodes + 1, INT_MAX);
    lengths.at(0) = 0;
    queue<tuple<int, int, int>> q;
    for (auto e : edges) {
        if (get<0>(e) == 0) {
            q.push(e);
        }
    }
    while (!q.empty()) {
        int newLength = lengths.at(get<0>(q.front())) + get<2>(q.front());
        if (newLength < lengths.at(get<1>(q.front()))) {
            lengths.at(get<1>(q.front())) = newLength;
            for (auto e : edges) {
                if (get<0>(e) == get<1>(q.front())) {
                    q.push(e);
                }
            }
        }
        q.pop();
    }
    for (auto l : lengths) {
        cout << l << endl;
        if (l > longest) {
            longest = l;
        }
    }


    return longest;
}

int main()
{
    vector<tuple<int, int, int>> edges = {
        make_tuple(0, 1, 5),
        make_tuple(0, 2, 3),
        make_tuple(0, 5, 4),
        make_tuple(1, 3, 8),
        make_tuple(2, 3, 1),
        make_tuple(3, 5, 10),
        make_tuple(3, 4, 5)
    };
    int nodes = 5;
    cout << minForAllNodes(edges, nodes) << endl;
}
