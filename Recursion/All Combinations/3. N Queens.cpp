#include <bits/stdc++.h>
using namespace std;

// Simple Recursion trying to put a queen on each col in a single row;

bool isSafe(int row, int col, vector<string>& board) {
    int n = board.size();

    // Check vertically upwards
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

void helper(int row, int n, vector<string> board, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col=0; col<n; col++) {
        if (isSafe(row, col ,board)) {
            board[row][col] = 'Q';
            helper(row + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    // Making Board
    vector<string> board(n, string(n, '.'));

    vector<vector<string>> ans;
    helper(0, n, board, ans);
    return ans;
}
