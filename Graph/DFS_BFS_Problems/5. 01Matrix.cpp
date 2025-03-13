#include <bits/stdc++.h>
using namespace std;

// BFS Approach 
// Time: O(N × M)
// Space: O(N × M)

// Pusing All Zeros to Queue and then pushing their adjacent Nodes while also updating their distances

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int, int>,int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] == 0) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();

        int drow[] =  {1, 0, -1, 0};
        int dcol[] =  {0, 1, 0, -1};

        for (int i=0; i<4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow < n and nrow >= 0 and
                ncol < m and ncol >= 0 and
                !vis[nrow][ncol]) {
                    q.push({{nrow, ncol}, d + 1});
                    mat[nrow][ncol] = d + 1;
                    vis[nrow][ncol] = 1;
                }
        }
    }
    return mat;
}