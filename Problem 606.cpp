// Problem 606.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*A knight's tour is a sequence of moves by a knight on a chessboard such that all squares are visited once.

Given N, write a function to return the number of knight's tours on an N by N chessboard.*/

#include <iostream>
#include <vector>
#include <ctime>

#define boardSize 5

using namespace std;

void printBoard(bool board[boardSize][boardSize]) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
}

bool validMove(int x, int y) {
    return x >= 0 && y >= 0 && x < boardSize && y < boardSize;
}

bool checkBoard(bool board[boardSize][boardSize]) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (!board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

long totalToursForSpace(bool board[boardSize][boardSize], int x, int y, int visitedCount) {
    vector<pair<int, int>> knightMoves = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1} };
    if (validMove(x, y) && !board[x][y]) {
        board[x][y] = true;
        visitedCount++;
        if (visitedCount == boardSize * boardSize) {
        //if (checkBoard(board)) {
            board[x][y] = false;
            return 1;
        }
        else {
            long tempTotal = 0;
            for (auto k : knightMoves) {
                tempTotal += totalToursForSpace(board, x + k.first, y + k.second, visitedCount);
            }
            board[x][y] = false;
            return tempTotal;
        }
    }
    return 0;
}

long numberOfTotalTours() {
    bool board[boardSize][boardSize] = { false };
    int half = boardSize - boardSize / 2;
    long total = 0;
    if (boardSize % 2 == 0) {
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                if (i == j) {
                    total += 4*totalToursForSpace(board, i, j, 0);
                }
                else if (i > j) {
                    total += 8 * totalToursForSpace(board, i, j, 0);
                }
            }
        }
    }
    else {
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                if (i == j && i == half - 1) {
                    total += totalToursForSpace(board, i, j, 0);
                }
                else if (i == j) {
                    total += 4 * totalToursForSpace(board, i, j, 0);
                }
                else if (i == half - 1) {
                    total += 4 * totalToursForSpace(board, i, j, 0);
                }
                else if ((i > j)) {
                    total += 8 * totalToursForSpace(board, i, j, 0);
                }
            }
        }
    }
    /*for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            total += totalToursForSpace(board, i, j, 0);
        }
    }*/
    return total;
}


int main()
{
    clock_t start = clock();
    cout << "Total knight's tours: " << numberOfTotalTours() << endl;
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time: " << elapsed << " seconds" << endl;
    return 0;
}
