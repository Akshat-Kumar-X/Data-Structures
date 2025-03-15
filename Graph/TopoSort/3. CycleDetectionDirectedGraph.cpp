#include <bits/stdc++.h>
using namespace std;

// BFS approach
// Time: O(v + E)
// Space: O(V + E)

// Simple BFS with a inDegree arr , processing nodes with 0 indegree and removing them.
// after removing them updating the inDegree of their adj Nodes and repeating process.

// if all notes not processed then Loop found;

bool detectCycle(vector<vector<int>>& adj) {
    int n = adj.size();

    vector<int> inDegree(n, 0);

    // Calculate the in-degree for each node
    for (int i = 0; i < n; i++) {
        for (auto node: adj[i]) {
            inDegree[node]++;
        }
    }

    queue<int> q;

    // Push nodes with zero in-degree into the queue
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;  // Counter to track the number of processed nodes

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        // Reduce the in-degree of the adjacent nodes
        for (auto it: adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If the count of processed nodes is not equal to the total number of nodes, there is a cycle
    return count != n;
}