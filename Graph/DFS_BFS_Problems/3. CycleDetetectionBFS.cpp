#include <bits/stdc++.h>
using namespace std;

// BFS Approach 
// Time: O(V + E)

// undirected Graph

// Storing Parent Along with Parent in queue, 
// if already Visited node is not current nodes parent then its a loop

bool detectCycle(int node, vector<int>& vis, vector<vector<int>>& adj) {
    queue<pair<int, int>> q;
    q.push({node, -1});
    vis[node] = 1;
    
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        vis[node] = 1;
        q.pop();
        
        for (auto it: adj[node]) {
            if (!vis[it]) 
                q.push({it, node});
            else if (vis[it] and it != parent){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0);
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            if (detectCycle(i, vis, adj)) return true;
        }
    }
    return false;
}