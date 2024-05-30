// Problem 581.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given two rectangles on a 2D graph, return the area of their intersection. If the rectangles don't intersect, return 0.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}
and

{
    "top_left": (0, 5),
    "dimensions": (4, 3) # width, height
}
return 6.*/

#include <iostream>

using namespace std;

struct Rectangle {
    pair<int, int> top_left;
    pair<int, int> dimensions;
    int upperBound;
    int lowerBound;
    int leftBound;
    int rightBound;

    // Default constructor
    Rectangle() : top_left(std::make_pair(0, 0)), dimensions(std::make_pair(0, 0)) {
        upperBound = 0;
        lowerBound = 0;
        leftBound = 0;
        rightBound = 0;
    }

    // Constructor for easy initialization
    Rectangle(int x1, int y1, int width, int height) : top_left(x1, y1), dimensions(width, height) {
        upperBound = top_left.second;
        lowerBound = top_left.second - dimensions.second;
        leftBound = top_left.first;
        rightBound = top_left.first + dimensions.first;
    }

    void print() {
        cout << "Top-left: (" << top_left.first << ", " << top_left.second << ")" << endl;
        cout << "Dimensions: (" << dimensions.first << ", " << dimensions.second << ")" << endl;
        cout << "Top: " << upperBound << " Bottom: " << lowerBound << " Left: " << leftBound << " Right: " << rightBound << endl;
    }
};

int overlappingArea(Rectangle rect1, Rectangle rect2) {
    int area = 0;
    rect1.print();
    rect2.print();
    int overlapX;
    int overlapY;
    Rectangle top;
    Rectangle bottom;
    Rectangle right;
    Rectangle left;

    if (rect1.upperBound > rect2.upperBound) {
        top = rect1;
        bottom = rect2;
    }
    else {
        top = rect2;
        bottom = rect1;
    }
    if (top.lowerBound > bottom.upperBound) {
        return 0;
    }
    if (top.lowerBound < bottom.lowerBound) {
        overlapY = bottom.upperBound - bottom.lowerBound;
    }
    else {
        overlapY = bottom.upperBound - top.lowerBound;
    }

    if (rect1.rightBound > rect2.rightBound) {
        right = rect1;
        left = rect2;
    }
    else {
        right = rect2;
        left = rect1;
    }
    if (right.leftBound > left.rightBound) {
        return 0;
    }
    if (right.leftBound < left.leftBound) {
        overlapX = left.rightBound - left.leftBound;
    }
    else {
        overlapX = left.rightBound - right.leftBound;
    }

    //top.print();
    //bottom.print();

    area = overlapX * overlapY;
    return area;
}

int main()
{
    Rectangle rect1(1, 4, 3, 3);
    Rectangle rect2(0, 5, 4, 3);
    cout << overlappingArea(rect1, rect2) << endl;

    Rectangle rect3(1, 1, 3, 3);
    Rectangle rect4(5, 5, 3, 3);
    std::cout << overlappingArea(rect3, rect4) << std::endl;

    Rectangle rect5(1, 1, 5, 5);
    Rectangle rect6(2, 2, 3, 3);
    std::cout << overlappingArea(rect5, rect6) << std::endl;

    Rectangle rect7(1, 1, 5, 5);
    Rectangle rect8(4, 1, 3, 3);
    std::cout << overlappingArea(rect7, rect8) << std::endl;

    Rectangle rect9(1, 1, 5, 1);
    Rectangle rect10(3, 0, 1, 5);
    std::cout << overlappingArea(rect9, rect10) << std::endl;

    Rectangle rect11(1, 1, 1, 1);
    Rectangle rect12(0, 3, 3, 3 );
    std::cout << overlappingArea(rect11, rect12) << std::endl;
}
