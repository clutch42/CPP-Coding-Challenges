// Problem 626.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestProduct(vector<int>& list) {
	int product;
	sort(list.begin(), list.end());
	if (list[0] * list[1] > list[list.size() - 2] * list[list.size() - 3]) {
		product = list[0] * list[1] * list[list.size() - 1];
	}
	else {
		product = list[list.size() - 1] * list[list.size() - 2] * list[list.size() - 3];
	}

	return product;
}

int main()
{
	vector<int> list = { 5, 2, 10, -50};
	for (auto l : list) {
		cout << l << " ";
	}
	cout << endl;
	cout << largestProduct(list) << endl;
	for (auto l : list) {
		cout << l << " ";
	}
	cout << endl;
}
