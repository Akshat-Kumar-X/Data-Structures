#include <bits/stdc++.h>
using namespace std;

// Simple DFS for Graph from src to dest

void dfs(int r, int c, string path, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<string>& ans) {
    int n = grid.size();
    if (r == n-1 and c == n-1) {
        ans.push_back(path);
        return;
    }
    
    vector<int> drow = {1, 0, -1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    for (int i=0; i<4; i++) {
        int nrow = r + drow[i];
        int ncol = c + dcol[i];
        if (nrow < n and ncol < n and nrow >= 0 and ncol >= 0 and !vis[nrow][ncol] and grid[nrow][ncol] == 1) {
            vis[nrow][ncol] = 1;

            if (i == 0) path += 'D';
            else if (i == 1) path += 'R';
            else if (i == 2) path += 'U';
            else path += 'L';

            dfs(nrow, ncol, path, vis, grid, ans);
            path.pop_back();
            vis[nrow][ncol] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;
    dfs( 0, 0, "", vis, grid, ans);
    return ans;
}