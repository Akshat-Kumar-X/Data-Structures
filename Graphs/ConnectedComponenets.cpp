#include <bits/stdc++.h>
using namespace std;

class Count_Connected_Components {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node) {
        vis[node] = 1;
        int N = isConnected.size();
        for (int j = 0; j < N; j++) {
            if (!vis[j] && isConnected[node][j]) {
                dfs(isConnected, vis, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int> vis(N, 0);
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                count++;
                dfs(isConnected, vis, i);
            }
        }
        
        return count;
    }
};
