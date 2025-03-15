#include <bits/stdc++.h>
using namespace std;

// Simple any Loop Detection Algo on each Node, if Loop detected from that Node its Not safe else it is.

bool detectCycle(int node, vector<int>& pathVis, vector<int>& vis, vector<vector<int>>& adj) {
    pathVis[node] = 1;
    vis[node] = 1;

    for (auto it: adj[node]) {
        if (!vis[it]) {
            if (detectCycle(it, pathVis, vis, adj)) return true;
        } else if (pathVis[it]) {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    vector<int> result;

    for (int i=0; i<n; i++) {
        if (detectCycle(i, pathVis, vis, graph) == false) {
            result.push_back(i);
        }
    }
    return result;
}