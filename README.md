# Coding-Challenges
## Problem 578
Determine whether there exists a one-to-one character mapping from one string s1 to another s2.
For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.
Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.

## Problem 579
Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.
On the ith jump, you may move exactly i places to the left or right.
Find a path with the fewest number of jumps required to get from 0 to N.

## Problem 580
Given a binary tree, find a minimum path sum from root to a leaf.
```
  10
 /  \
5    5
 \     \
   2    1
       /
     -1
```
For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

## Problem 581
Given two rectangles on a 2D graph, return the area of their intersection. If the rectangles don't intersect, return 0.
For example, given the following rectangles:
```
{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}
```
and
```
{
    "top_left": (0, 5),
    "dimensions": (4, 3) # width, height
}
```
return 6.

## Problem 582
Let X be a set of n intervals on the real line. We say that a set of points P "stabs" X if every interval in X contains at least one point in P. Compute the smallest set of points that stabs X.
For example, given the intervals [(1, 4), (4, 5), (7, 9), (9, 12)], you should return [4, 9]

## Problem 583
You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.
For example, in this matrix
```
0 3 1 1
2 0 0 4
1 5 3 1
```
The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.

## Problem 584
Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.
For example, given "aaabbc", you could return "ababac". Given "aaab", return None.

## Problem 585
Given an N by M matrix consisting only of 1's and 0's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:
```
[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
```
Return 4.

## Problem 586
You are given a list of (website, user) pairs that represent users visiting websites. Come up with a program that identifies the top k pairs of websites with the greatest similarity.
For example, suppose k = 1, and the list of tuples is:
```
[('a', 1), ('a', 3), ('a', 5),
 ('b', 2), ('b', 6),
 ('c', 1), ('c', 2), ('c', 3), ('c', 4), ('c', 5)
 ('d', 4), ('d', 5), ('d', 6), ('d', 7),
 ('e', 1), ('e', 3), ('e': 5), ('e', 6)]
```
Then a reasonable similarity metric would most likely conclude that a and e are the most similar, so your program should return [('a', 'e')].

## Problem 587
Given a binary tree, return all paths from the root to leaves.
For example, given the tree:
```
   1
  / \
 2   3
    / \
   4   5
```
Return [[1, 2], [1, 3, 4], [1, 3, 5]].

## Problem 588
You have a large array with most of the elements as zero.
Use a more space-efficient data structure, SparseArray, that implements the same interface:
- init(arr, size): initialize with the original large array and size.
- set(i, val): updates index at i with val.
- get(i): gets the value at index i.

## Problem Alice wants to join her school's Probability Student Club. Membership dues are computed via one of two simple probabilistic games.

The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six. Your number of rolls is the amount you pay, in dollars.
The second game: same, except that the stopping condition is a five followed by a five.
Which of the two games should Alice elect to play? Does it even matter? Write a program to simulate the two games and calculate their expected value.

## Problem 593
You are given an array representing the heights of neighboring buildings on a city street, from east to west. The city assessor would like you to write an algorithm that returns how many of these buildings have a view of the setting sun, in order to properly value the street.
For example, given the array [3, 7, 8, 3, 6, 1], you should return 3, since the top floors of the buildings with heights 8, 6, and 1 all have an unobstructed view to the west.
Can you do this using just one forward pass through the array?

## Problem 595
The number 6174 is known as Kaprekar's contant, after the mathematician who discovered an associated property: for all four-digit numbers with at least two distinct digits, repeatedly applying a simple procedure eventually results in this value. The procedure is as follows:
- For a given input x, create two new numbers that consist of the digits in x in ascending and descending order.
- Subtract the smaller number from the larger number.

For example, this algorithm terminates in three steps when starting from 1234:
- 4321 - 1234 = 3087
- 8730 - 0378 = 8352
- 8532 - 2358 = 6174

Write a function that returns how many steps this will take for a given input N.

## Problem 596
Invert a binary tree.
For example, given the following tree:
```
    a
   / \
  b   c
 / \  /
d   e f
```
should become:
```
  a
 / \
 c  b
 \  / \
  f e  d
```
## Problem 597
Given an array of integers, determine whether it contains a Pythagorean triplet. 
Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2.

## Problem 598
You have n fair coins and you flip them all at the same time. Any that come up tails you set aside. The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?
Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.
