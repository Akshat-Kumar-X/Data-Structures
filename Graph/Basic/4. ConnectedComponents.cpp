#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for (auto it: adj[node]) {
        if (!vis[it])
            DFS(it, adj, vis);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int n = adj.size();
    vector<int> vis(n, 0);

    int count = 0;
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            count++;
            DFS(i, adj, vis);
        }
    }
    cout << count;
}