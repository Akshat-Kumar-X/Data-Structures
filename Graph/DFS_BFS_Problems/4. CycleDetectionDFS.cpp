#include <bits/stdc++.h>
using namespace std;

// DFS Approach 
// Time: O(V + E)

// undirected Grapgh

// keeping Track of parents in DFS calls
// if node is already visited and is not a parent then loop found

bool detectCycle(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (detectCycle(it, node, vis, adj)) return true;
        }
        else if (vis[it] and it != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (detectCycle(i, -1, vis, adj)) return true;
        }
    }
    return false;
}