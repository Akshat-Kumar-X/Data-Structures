#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

// Time: V x E

// Simply Going Through All Edges V-1 Times and checking if dist[u] + wt < dist[v]
// if yes then update. if even after v-1 times dist is still updating then its a negetive cycle.

vector<int> BellmonFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for (int i=0; i<V-1; i++) {
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 and dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 and dist[u] + wt < dist[v]) {
            return {-1};
        }
    }
    return dist;
}