#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis = image;
        queue <pair<pair<int, int>, int>> q;

        q.push({{sr, sc}, image[sr][sc]});
        vis[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int nColor = q.front().second;
            q.pop();

            for (int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >=0 and nrow <n and
                    ncol >=0 and ncol <m and
                    image[nrow][ncol] == nColor and
                    vis[nrow][ncol] != color) {
                        
                        q.push({{nrow, ncol}, nColor});
                        vis[nrow][ncol] = color;
                }
            }
        }
        return vis;
    }
};