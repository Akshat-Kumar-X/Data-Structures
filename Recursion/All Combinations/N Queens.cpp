#include <bits/stdc++.h>
using namespace std;
bool safe(int row, int col, vector<string>& board) {
    int n = board.size();
    int r = row;
    int c = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = r;
    col = c;
    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    row = r;
    col = c;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans) {
    if (col == board.size()) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < board.size(); row++) {
        if (safe(row, col, board)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> nQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    solve(0, board, ans);
    return ans;
}
