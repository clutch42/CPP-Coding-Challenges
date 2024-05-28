# Coding-Challenges
Problem 578 - Determine whether there exists a one-to-one character mapping from one string s1 to another s2.
  For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.
  Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.

Problem 579 - Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.
  On the ith jump, you may move exactly i places to the left or right.
  Find a path with the fewest number of jumps required to get from 0 to N.

Problem 580 - Given a binary tree, find a minimum path sum from root to a leaf.
```
  10
 /  \
5    5
 \     \
   2    1
       /
     -1```
For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

Problem 583 - You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.
For example, in this matrix
>0 3 1 1
>2 0 0 4
>1 5 3 1
The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.

Problem 584 - Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.
  For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
