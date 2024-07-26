// Problem 634.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*You are given a histogram consisting of rectangles of different heights. These heights are represented 
in an input list, such that [1, 3, 2, 5] corresponds to the following diagram:

      x
      x  
  x   x
  x x x
x x x x

Determine the area of the largest rectangle that can be formed only from the bars of the histogram. For 
the diagram above, for example, this would be six, representing the 2 x 3 area at the bottom right.*/

#include <iostream>
#include <vector>

using namespace std;

int largestRectangle(vector<int> histogram) {
    int maxArea = 0;
    int height = 1;
    int length = 0;
    bool cont = true;
    while (cont) {
        for (int i = 0; i < histogram.size(); i++) {
            if (histogram[i] > 0 && i < histogram.size() - 1) {
                length++;
                histogram[i]--;
            }
            else if (histogram[i] > 0 && i == histogram.size() - 1) {
                length++;
                histogram[i]--;
                if (length * height > maxArea) {
                    maxArea = length * height;
                }
                length = 0;
            }
            else {
                if (length * height > maxArea) {
                    maxArea = length * height;
                }
                length = 0;
            }
        }
        height++;
        cont = false;
        for (int i = 0; i < histogram.size(); i++) {
            if (histogram[i] > 0) {
                cont = true;
            }
        }
    }

    return maxArea;
}

int main()
{
    vector<int> histogram = { 1, 3, 2, 5};
    cout << "Largest rectangle area: " << largestRectangle(histogram) << endl;
}
