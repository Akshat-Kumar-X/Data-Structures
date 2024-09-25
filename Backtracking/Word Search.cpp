#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int index, int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board, string word) {
        if (index == word.length()) {
            return true;
        }

        int n = board.size();
        int m = board[0].size();

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, -1, 0, 1};

        for (int i=0; i<4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and !vis[nrow][ncol] and board[nrow][ncol] == word[index]) {
                vis[nrow][ncol] = 1;
                if (dfs(index + 1, nrow, ncol, vis, board, word)) return true;
                vis[nrow][ncol] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] and board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if (dfs(1, i, j, vis, board, word)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};