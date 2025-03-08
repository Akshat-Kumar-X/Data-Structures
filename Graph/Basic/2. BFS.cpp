#include <bits/stdc++.h>
using namespace std;

// Time: O(N) + O(2E); for loop running for all neighboring nodes; 2 for unDirected, 1 for Directed Graph
// Space: O(N);

vector<int> BFS(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0);

    queue <int> q;
    vis[0] = 1;
    q.push(0);

    vector<int> result;

    while ( q.empty() ) {
        int node = q.front();
        result.push_back(node);
        vis[node] = 1;
        q.pop();

        for (auto it: adj[node]) {
            if (!vis[n])
                q.push(n);
        }
    }
    return result;
}