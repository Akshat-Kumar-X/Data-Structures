#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>> graph) {
        color[node] = col;
        for (auto x: graph[node]) {
            if (color[x] == -1) {
                if(!dfs(x, !col, color, graph)) return false;
            } else if (col == color[x]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i=0; i<V; i++) {
            if (color[i] == -1) {
                if(!dfs(i, 0, color, graph))return false;
            }
        }
        return true;
    }
};