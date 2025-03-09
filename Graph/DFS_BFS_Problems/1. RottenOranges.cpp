#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> mat = grid;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int maxTime = 0;
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;
        maxTime = max(time, maxTime);
        q.pop();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i=0; i<4; i++) {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;

            if (nrow < n and nrow >=0 and 
                ncol < m and ncol >=0 and 
                !vis[nrow][ncol] and mat[nrow][ncol] == 1) 
            {
                vis[nrow][ncol] = 1;
                mat[nrow][ncol] = 2;
                q.push({{nrow, ncol}, time + 1});
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] == 1) {
                return -1;
            }
        }
    }
    return maxTime;
}
