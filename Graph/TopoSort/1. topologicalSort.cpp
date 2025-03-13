#include <bits/stdc++.h>
using namespace std;

// DFS approach
// Time: O(v + E)
// Space: O(V + E)

// Simple DFS with a stack, pushing nodes in stack whose calls are done.

void DFS(int node, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj) {
    vis[node] = 1;
    
    for (auto it: adj[node]) {
        if (!vis[it])
            DFS(it, st, vis, adj);
    }
    
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    
    vector<int> vis(n, 0);
    stack<int> st;
    
    for (int i=0; i<n; i++) {
        if (!vis[i])
            DFS(i, st, vis, adj);
    }

    vector<int> result;
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}