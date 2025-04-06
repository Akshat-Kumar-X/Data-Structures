#include <iostream>
#include <climits>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

// Pushing 0,src in PQ then going to adjacent nodes to check their distance maintaining a dist array
// Time - E Log V
int main() {
    vector<vector<pair<int, int>>> adj; // Node, Weight
    int n = adj.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX);

    vector<int> parent(n);                 // keeping track of parent for path
    for (int i=0;i<n; i++) parent[i] = i;

    int src = 0;
    dist[src] = 0;

    pq.push({0, 0}); // Distance , Node

    while (!pq.empty()) {
        auto it = pq.top();
        int distance = it.first;
        int node = it.second;
        pq.pop();

        for (auto adjNode : adj[node]) {
            int neighbor = adjNode.first;
            int wt = adjNode.second;
            
            if (distance + wt < dist[neighbor]) {
                dist[neighbor] = distance + wt;
                pq.push({distance + wt, neighbor});
                parent[neighbor] = node;
            }
        }
    }

    int destination = 5;
    if (dist[destination] == INT_MAX) return -1; //for unreachable dest

    // Getting Path from src to dest
    vector<int> path;
    int node = destination;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);

    return 0;
}