#include <bits/stdc++.h>
using namespace std;

// DFS Approach 
// Time: O(V + E)
// Space: O(V)

// Directed Grapgh

// keeping Track of Visited Paths in DFS calls, marking unVistited Paths once backtracked
// if node is already visited and that Path is also already Visted then loop found

bool detectCycle(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (detectCycle(it, vis, pathVis, adj)) return true;
            
        }
        else if (vis[it] and pathVis[it]) {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (detectCycle(i, vis, pathVis, adj)) return true;
        }
    }
    return false;
}