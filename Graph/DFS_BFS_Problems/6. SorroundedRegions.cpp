#include <bits/stdc++.h>
using namespace std;

// BFS Approach 
// Time: O(N × M)
// Space: O(N × M)

// Pushing Lands connected to Boundary into queue and Peroforming BFS on Them,
// rest islands will submurge

void BFS(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i=0; i<4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow < n and nrow >= 0 and 
                ncol < m and ncol >= 0 and 
                board[nrow][ncol] == 'O' and 
                !vis[nrow][ncol]) {
                    
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
        }
    }
}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((i == 0 or i == n-1 or j == 0 or j == m-1) and 
                board[i][j] == 'O') {
                BFS(i, j, vis, board);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!vis[i][j]) {
                board[i][j] = 'X';
            }
        }
    }
}