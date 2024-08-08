#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> ans;
        vector<int> vis(V, 0);

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto x : adj[node]) {
                if (!vis[x]) {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        return ans;
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
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
