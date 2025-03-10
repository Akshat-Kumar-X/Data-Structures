#include <bits/stdc++.h>
using namespace std;

// BFS Approach 
// Time: O(V + E)

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;
    int initColor = image[sr][sc];
    image[sr][sc] = color;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i=0; i<4; i++) {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;

            if (nrow < n and nrow >= 0 and
                ncol < m and ncol >= 0 and
                !vis[nrow][ncol] and image[nrow][ncol] == initColor) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                }
        }
    }
    return image;
}