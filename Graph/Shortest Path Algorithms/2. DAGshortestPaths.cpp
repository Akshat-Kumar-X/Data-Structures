#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

// finding Shortest Distance in Weighted DAG

// Simple Toposort, traversing the stack and Updating distance values in dist array

void topoSort(int node, stack<int>& st,vector<int>& vis, vector<vector<pair<int, int>>>& adj) {
    vis[node] = 1;
    
    for (auto adjNode: adj[node]) {
        int v = adjNode.first;
        if (!vis[v])
            topoSort(v, st, vis, adj);
    }
    st.push(node);
}


int main() {
    vector<vector<pair<int, int>>> adj;
    int n = adj.size();

    vector<int> vis(n, 0);

    stack<int> st;
    int src = 0;
    for (int i=0; i<n; i++) {
        if (!vis[i])
            topoSort(i, st, vis, adj);
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while(!st.empty()) {
        int node = st.top();
        int distance = dist[node];
        st.pop();

        if (distance != INT_MAX) { // if Distance is still INT_MAX its an Unreachable Node
            for (auto adjNode: adj[node]) {
                int v = adjNode.first;
                int wt = adjNode.second;
                if (distance + wt < dist[v])
                    dist[v] = distance + wt;
            }
        }
    }
    return 0;
}