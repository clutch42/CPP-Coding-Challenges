// Problem 600.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a set of points (x, y) on a 2D cartesian plane, find the two closest points. 
For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)], return [(-1, -1), (1, 1)].*/

#include <iostream>
#include <utility>
#include <vector>
#include <limits.h>

using namespace std;

vector<pair<int, int>> getClosest(const vector<pair<int, int>>& list) {
	vector<pair<int, int>> closestTwo = {};
	if (list.size() < 2) {
		return closestTwo;
	}
	int minDist = INT_MAX;
	for (size_t i = 0; i < list.size() - 1; i++) {
		for (size_t j = i+1; j < list.size(); j++) {
			int tempX = list.at(i).first - list.at(j).first;
			int tempY = list.at(i).second - list.at(j).second;
			int tempTotal = tempX * tempX + tempY * tempY;
			if (minDist > tempTotal) {
				minDist = tempTotal;
				closestTwo.clear();
				closestTwo.push_back(list.at(i));
				closestTwo.push_back(list.at(j));
			}
		}
	}
	return closestTwo;
}

int main()
{
	vector<pair<int, int>> listCoord = { make_pair(1, 1), make_pair(-1, -1), make_pair(3, 4), make_pair(6, 1), make_pair(-1, 0), make_pair(-4, -3) };
	vector<pair<int, int>> closestTwo = getClosest(listCoord);
	cout << "Closest two points: ";
	for (auto c : closestTwo) {
		cout << "(" << c.first << ", " << c.second << ") ";
	}
	cout << endl;
}
