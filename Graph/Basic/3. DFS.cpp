#include <bits/stdc++.h>
using namespace std;

// Time: O(N) + O(2E); for loop running for all neighboring nodes; 2 for unDirected, 1 for Directed Graph
// Space: O(N);

void DFS(int node, vector<int>& vis, vector<int>& result, vector<vector<int>>& adj) {
    vis[node] = 1;
    result.push_back(node);

    for (auto it: adj[node]) {
        if (!vis[it]) {
            DFS(it, vis, result, adj);
        }
    }
}

int main() {
    vector<vector<int>> adj; // Given

    int n = adj.size();
    vector<int> vis(n, 0);
    vector<int> result;

    DFS(0, vis, result, adj);
}