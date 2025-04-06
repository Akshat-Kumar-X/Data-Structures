#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

// Shortest Path Algorithm for Undirected Graph
// BFS traversal with distance array initiated with INT_MAX and update the distance starting from src


using namespace std;

vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int adjNode : adj[node]) {
            if (dist[adjNode] == INT_MAX) { // Only push if not visited
                dist[adjNode] = dist[node] + 1;
                q.push(adjNode);
            }
        }
    }

    for (int& num : dist) {
        if (num == INT_MAX) {
            num = -1;
        }
    }
    return dist;
}


