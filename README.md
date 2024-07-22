# Coding-Challenges
<details>
<summary>
  
## Problem 578 - Strings
</summary>
Determine whether there exists a one-to-one character mapping from one string s1 to another s2.
For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.
Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
</details>
<details>
<summary>
  
## Problem 579 - Pathfinding
</summary>
Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.
On the ith jump, you may move exactly i places to the left or right.
Find a path with the fewest number of jumps required to get from 0 to N.
</details>
<details>
<summary>
  
## Problem 580 - Pathfinding
</summary>
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
</details>
<details>
<summary>
  
## Problem 581 - Intersection
</summary>
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
</details>
<details>
<summary>
  
## Problem 582 - Intervals
</summary>
Let X be a set of n intervals on the real line. We say that a set of points P "stabs" X if every interval in X contains at least one point in P. Compute the smallest set of points that stabs X.
For example, given the intervals [(1, 4), (4, 5), (7, 9), (9, 12)], you should return [4, 9]
</details>
<details>
<summary>
  
## Problem 583 - Pathfinding
</summary>
You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.
For example, in this matrix

```
0 3 1 1
2 0 0 4
1 5 3 1
```

The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
</details>
<details>
<summary>
  
## Problem 584 - Strings
</summary>
Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.
For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
</details>
<details>
<summary>
  
## Problem 585 - Area
</summary>
Given an N by M matrix consisting only of 1's and 0's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

```
[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
```

Return 4.
</details>
<details>
<summary>
  
## Problem 586 - Similarity
</summary>
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
</details>
<details>
<summary>
  
## Problem 587 - Binary Tree Paths
</summary>
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
</details>
<details>
<summary>
  
## Problem 588 - Data Structure
</summary>
You have a large array with most of the elements as zero.
Use a more space-efficient data structure, SparseArray, that implements the same interface:
- init(arr, size): initialize with the original large array and size.
- set(i, val): updates index at i with val.
- get(i): gets the value at index i.
</details>
<details>
<summary>
  
## Problem 589 - Probability
</summary>
Alice wants to join her school's Probability Student Club. Membership dues are computed via one of two simple probabilistic games.
The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six. Your number of rolls is the amount you pay, in dollars.
The second game: same, except that the stopping condition is a five followed by a five.
Which of the two games should Alice elect to play? Does it even matter? Write a program to simulate the two games and calculate their expected value.
</details>
<details>
<summary>
  
## Problem 590 - XOR Linked List
</summary>
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields,
it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has
an add(element) which adds the element to the end, and a get(index) which returns the node at index.
If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and
dereference_pointer functions that converts between nodes and memory addresses.
</details>
<details>
<summary>

## Problem 592 - Matrix Islands
</summary>
Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.
For example, this matrix has 4 islands.

```
1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
```
</details>
<details>
<summary>

## Problem 593 - Arrays Height
</summary>
You are given an array representing the heights of neighboring buildings on a city street, from east to west. The city assessor would like you to write an algorithm that returns how many of these buildings have a view of the setting sun, in order to properly value the street.
For example, given the array [3, 7, 8, 3, 6, 1], you should return 3, since the top floors of the buildings with heights 8, 6, and 1 all have an unobstructed view to the west.
Can you do this using just one forward pass through the array?
</details>
<details>
<summary>
  
## Problem 595 - Kaprekar's Constant
</summary>
The number 6174 is known as Kaprekar's constant, after the mathematician who discovered an associated property: for all four-digit numbers with at least two distinct digits, repeatedly applying a simple procedure eventually results in this value. The procedure is as follows:
- For a given input x, create two new numbers that consist of the digits in x in ascending and descending order.
- Subtract the smaller number from the larger number.

For example, this algorithm terminates in three steps when starting from 1234:
- 4321 - 1234 = 3087
- 8730 - 0378 = 8352
- 8532 - 2358 = 6174

Write a function that returns how many steps this will take for a given input N.
</details>
<details>
<summary>
  
## Problem 596 - Invert binary tree
</summary>
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
</details>
<details>
<summary>
  
## Problem 597 - Pythagorean Triplet
</summary>
Given an array of integers, determine whether it contains a Pythagorean triplet. 
Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2.
</details>

## Problem 598
You have n fair coins and you flip them all at the same time. Any that come up tails you set aside. The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?
Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.

## Problem 600
Given a set of points (x, y) on a 2D cartesian plane, find the two closest points. For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)], return [(-1, -1), (1, 1)].

## Problem 601
The sequence [0, 1, ..., N] has been jumbled, and the only clue you have for its order is an array 
representing whether each number is larger or smaller than the last. Given this information, reconstruct 
an array that is consistent with it. For example, given [None, +, +, -, +], you could return [1, 2, 3, 0, 4].

## Problem 602
Suppose you are given two lists of n points, one list p1, p2, ..., pn on the line y = 0 
and the other list q1, q2, ..., qn on the line y = 1. Imagine a set of n line segments connecting 
each point pi to qi. Write an algorithm to determine how many pairs of the line segments intersect.
<details>
<summary>
  
## Problem 604 - Soundex Algorithm
</summary>
Soundex is an algorithm used to categorize phonetically, such that two names that sound alike but are spelled differently have the same representation.

Soundex maps every name to a string consisting of one letter and three numbers, like M460.

One version of the algorithm is as follows:

Remove consecutive consonants with the same sound (for example, change ck -> c).
Keep the first letter. The remaining steps only apply to the rest of the string.
Remove all vowels, including y, w, and h.
Replace all consonants with the following digits:
```
b, f, p, v → 1
c, g, j, k, q, s, x, z → 2
d, t → 3
l → 4
m, n → 5
r → 6
```
If you don't have three numbers yet, append zeros until you do. Keep the first three numbers.
Using this scheme, Jackson and Jaxen both map to J250.

Implement Soundex.
</details>
<details>
<summary>

## Problem 605 - H-Index
</summary>
In academia, the h-index is a metric used to calculate the impact of a researcher's papers. It is calculated as follows:
A researcher has index h if at least h of her N papers have h citations each. If there are multiple h satisfying this formula, the maximum is chosen.
For example, suppose N = 5, and the respective citations of each paper are [4, 3, 0, 1, 5]. Then the h-index would be 3, since the researcher has 3 papers with at least 3 citations.
Given a list of paper citations of a researcher, calculate their h-index.
</details>
<details>
<summary>

## Problem 606 - Knight Tour
</summary>
A knight's tour is a sequence of moves by a knight on a chessboard such that all squares are visited once.

Given N, write a function to return the number of knight's tours on an N by N chessboard.
</details>

## Problem 607
There are M people sitting in a row of N seats, where M < N. Your task is to redistribute people such that there are no gaps between any of them, while keeping overall movement to a minimum.

For example, suppose you are faced with an input of [0, 1, 1, 0, 1, 0, 0, 0, 1], where 0 represents an empty seat and 1 represents a person. In this case, one solution would be to place the person on the right in the fourth seat. We can consider the cost of a solution to be the sum of the absolute distance each person must move, so that the cost here would be five.

Given an input such as the one above, return the lowest possible cost of moving people to remove all gaps.

## Problem 608
Given a start word, an end word, and a dictionary of valid words, find the shortest transformation sequence from start to end such that only one letter is changed at each step of the sequence, and each transformed word exists in the dictionary. If there is no possible transformation, return null. Each word in the dictionary have the same length as start and end and is lowercase.
For example, given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"}, return ["dog", "dot", "dat", "cat"].
Given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"}, return null as there is no possible transformation from dog to cat.

## Problem 609
Given a node in a binary search tree, return the next bigger element, also known as the inorder successor.
For example, the inorder successor of 22 is 30.
```
   10
  /  \
 5    30
     /  \
   22    35
```
You can assume each node has a parent pointer.

## Problem 610
Implement division of two positive integers without using the division, multiplication, 
or modulus operators. Return the quotient as an integer, ignoring the remainder.


## Problem 611
Create a data structure that performs all the following operations in O(1) time:

plus: Add a key with value 1. If the key already exists, increment its value by one.
minus: Decrement the value of a key. If the key's value is currently 1, remove it.
get_max: Return a key with the highest value.
get_min: Return a key with the lowest value.

## Problem 612
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered overlapping.
For example, given the intervals (7, 9), (2, 4), (5, 8), return 1 as the last interval can be removed and the first two won't overlap.
The intervals are not necessarily sorted in any order.

## Problem 613
Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map. If the key already exists, overwrite the value.
sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.
For example, you should be able to run the following code:
```
mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
```

## Problem 614
A network consists of nodes labeled 0 to N. You are given a list of edges (a, b, t), describing the time t 
it takes for a message to be sent from node a to node b. Whenever a node receives a message, it immediately 
passes the message on to a neighboring node, if possible.
Assuming all nodes are connected, determine how long it will take for every node to receive a message that begins at node 0.

For example, given N = 5, and the following edges:
```
edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
```
You should return 9, because propagating the message from 0 -> 2 -> 3 -> 4 will take that much time.
<details>
<summary>
  
## Problem 615 - Stable Marriage
</summary>
The stable marriage problem is defined as follows:

Suppose you have N men and N women, and each person has ranked their prospective opposite-sex partners in order of preference.

For example, if N = 3, the input could be something like this:
```
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
```
Write an algorithm that pairs the men and women together in such a way that no two people of opposite sex would both rather be with each other than with their current partners.
</details>
<details>
<summary>

## Problem 616 - Cryptarithmetic Puzzle
</summary>
A cryptarithmetic puzzle is a mathematical game where the digits of some numbers are represented by letters. Each letter represents a unique digit.

For example, a puzzle of the form:

```
  SEND
+ MORE
--------
 MONEY
```

may have the solution:

```
{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O', 0, 'R': 8, 'Y': 2}
```

Given a three-word puzzle like the one above, create an algorithm that finds a solution.
</details>
<details>
<summary>

## Problem 617 - Convert
</summary>
Given a number in Roman numeral format, convert it to decimal.

The values of Roman numerals are as follows:

```
{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}
```

In addition, note that the Roman numeral system uses subtractive notation for numbers such as IV and XL.

For the input XIV, for instance, you should return 14.
</details>
<details>
<summary>

## Problem 618 - Sort
</summary>
Given a list, sort it using this method: reverse(lst, i, j), which reverses lst from i to j.
</details>
<details>
<summary>

## Problem 619 - Pathfinding
</summary>
Given a 2D board of characters and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example, given the following board:

```
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
```

exists(board, "ABCCED") returns true, exists(board, "SEE") returns true, exists(board, "ABCB") returns false.
</details>
<details>
<summary>

## Problem 620 - Least Crossing Lines
</summary>
A wall consists of several rows of bricks of various integer lengths and uniform height. Your goal is to find a vertical line going from the top to the bottom of the wall that cuts through the fewest number of bricks. If the line goes through the edge between two bricks, this does not count as a cut.

For example, suppose the input is as follows, where values in each row represent the lengths of bricks in that row:

```
[[3, 5, 1, 1],
 [2, 3, 3, 2],
 [5, 5],
 [4, 4, 2],
 [1, 3, 3, 3],
 [1, 1, 6, 1, 1]]
```

The best we can we do here is to draw a line after the eighth brick, which will only require cutting through the bricks in the third and fifth row.

Given an input consisting of brick lengths for each row such as the one above, return the fewest number of bricks that must be cut to create a vertical line.
</details>
<details>
<summary>

## Problem 621 - Max Node Traversal
</summary>
Given a tree where each edge has a weight, compute the length of the longest path in the tree.

For example, given the following tree:

```
   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h
```
and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1, the longest path would be c -> a -> d -> f, with a length of 17.

The path does not have to pass through the root, and each node can have any amount of children.
</details>
<details>
<summary>

## Problem 622 - Deepest Node
</summary>
Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.

```
    a
   / \
  b   c
 /
d
```
</details>
<details>
<summary>
  
## Problem 623 - String Manipulation
</summary>
Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line. There should be at least one space between each word. Pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

```
["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
```
</details>
<details>
<summary>
  
## Problem 624 - String Manipulation
</summary>
Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid (i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.
</details>
<details>
<summary>
  
## Problem 625 - Binary Conversion
</summary>
Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.
</details>
<details>
<summary>
  
## Problem 626 - Max Product
</summary>
Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.
</details>
