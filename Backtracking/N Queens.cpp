#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool safe(int row, int col, vector<string>& board) {
        int n = board.size();
        int r = row;
        int c = col;
        while(row>=0 and col>=0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = r; col = c;
        while(col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }
        row = r; col = c;
        while(row < n and col>=0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans) {
        int n = board.size();
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row =0 ; row<n; row++) {
            if (safe(row, col, board) ) {
                board[row][col] = 'Q';
                solve(col+1, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, board, ans);
        return ans;
    }
};