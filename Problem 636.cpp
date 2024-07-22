// Problem 636.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. 
Find the minimum element in O(log N) time. You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.*/

#include <iostream>
#include <vector>

using namespace std;

int findMinimum(const vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    
    while (start < end) {
        int mid = (start + end) / 2;
        if (nums[mid] > nums[end]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }

    return nums[start];
}

int main()
{
    vector<int> nums = { 5, 7, 10, 3, 4 };
    int minimum = findMinimum(nums);
    cout << minimum << endl;
}
