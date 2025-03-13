#include <bits/stdc++.h>
using namespace std;

// BFS approach
// Time: O(v + E)
// Space: O(V + E)

// Simple BFS with a inDegree arr , processing nodes with 0 indegree and removing them.
// after removing them updating the inDegree of their adj Nodes and repeating process.

vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    
    vector<int> inDegree(n, 0);
    
    // Compute in-degree of all nodes
    for (const auto& node : adj) {
        for (int adjNode : node) {
            inDegree[adjNode]++;
        }
    }
    
    queue<int> q;
    // Push all nodes with in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }
    
    vector<int> result;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        // Reduce in-degree of adjacent nodes
        for (int adjNode : adj[node]) {
            inDegree[adjNode]--;
            if (inDegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }

    // Check if topological sorting is valid (DAG Check)
    if (result.size() != n) {
        cout << "Graph has a cycle, topological sorting not possible!" << endl;
        return {};
    }

    return result;
}