#include <bits/stdc++.h>
using namespace std;

//BFS

class Solution {
  public:
    bool detect(vector<int> adj[], vector<int>& vis, int root) {
        queue<pair<int, int>> q;
        q.push({root, -1});
        vis[root] = 1;
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjNode: adj[node]) {
                if (!vis[adjNode]) {
                    q.push({adjNode, node});
                    vis[adjNode] = 1;
                } 
                else if (parent != adjNode) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                if (detect(adj, vis, i)) return true;
            }
        }
        return false;
    }
};

//DFS

class Solution {
  public:
    bool detect(vector<int> adj[], vector<int>& vis, int node, int parent) {
        vis[node] = 1;
        for (auto adjNode: adj[node]) {
            if(!vis[adjNode]) {
                if(detect(adj, vis, adjNode, node))
                    return true;
            } else if (parent != adjNode) {
                return true;
            }
        }
        return false;
    } 
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                if(detect(adj, vis, i, -1)) 
                    return true;
            }
        }
        return false;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

