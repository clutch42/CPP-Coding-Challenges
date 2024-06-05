// Problem 593.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*You are given an array representing the heights of neighboring buildings on a city street, from east to west. The city assessor would like you to write an algorithm that returns how many of these buildings have a view of the setting sun, in order to properly value the street.

For example, given the array [3, 7, 8, 3, 6, 1], you should return 3, since the top floors of the buildings with heights 8, 6, and 1 all have an unobstructed view to the west.

Can you do this using just one forward pass through the array?*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> getView(vector<int> buildingHeights) {
	for (auto b : buildingHeights) {
		cout << b << endl;
	}
	vector<int> buildingWithView;
	buildingWithView.push_back(buildingHeights.at(0));
	for (int i = 1; i < buildingHeights.size(); i++) {
		while (!buildingWithView.empty() && buildingHeights.at(i) >= buildingWithView.back()) {
			buildingWithView.pop_back();
		}
		buildingWithView.push_back(buildingHeights.at(i));
	}
	return buildingWithView;
}

int main()
{
	vector<int> buildingHeights = { 9, 1, 7, 1, 5, 10 };
	vector<int> buildingsWithView = getView(buildingHeights);
	cout << "Buildings with a view:" << endl;
	for (auto b : buildingsWithView) {
		cout << b << endl;
	}
}
