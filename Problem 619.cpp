// Problem 619.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a 2D board of characters and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example, given the following board:

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
exists(board, "ABCCED") returns true, exists(board, "SEE") returns true, exists(board, "ABCB") returns false.*/

#include <iostream>
#include <vector>

using namespace std;

struct Cell {
    char value;
    bool available;

    Cell(char val) : value(val), available(true) {};
};

bool checkValidPos(vector<vector<Cell>>& board, int x, int y) {
    return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
}

bool checkValue(int x, int y, vector<vector<Cell>>& board, string search) {
    if (search.empty()) {
        return true;
    }
    if (!checkValidPos(board, x, y) || board[x][y].value != search[0] || !board[x][y].available) {
        return false;
    }
    board[x][y].available = false;
    bool found =checkValue(x + 1, y, board, search.substr(1)) ||
        checkValue(x - 1, y, board, search.substr(1)) ||
        checkValue(x, y + 1, board, search.substr(1)) ||
        checkValue(x, y - 1, board, search.substr(1));
    board[x][y].available = true;
    return found;
}

bool exists(vector<vector<Cell>>& board, string search) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (checkValue(i, j, board, search)) {
                return true;
            }
        }
        
    }

    return false;
}

int main()
{
    vector<vector<Cell>> board = {
        {Cell('A'), Cell('B'), Cell('C'), Cell('E')} ,
        {Cell('S'), Cell('F'), Cell('C'), Cell('S')},
        {Cell('A'), Cell('D'), Cell('E'), Cell('E')}
    };
    
    cout << exists(board, "ABCCED") << endl;
    cout << exists(board, "SEE") << endl;
    cout << exists(board, "ABCB") << endl;
    cout << exists(board, "ABCESEECFDAS") << endl;
}
