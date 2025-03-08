#include <bits/stdc++.h>
using namespace std;

int main() {
    // n - Nides , m - Edges
    int n, m;
    cin >> n >> m;

    // Adjacency Matrix Method :

    int adj[n+1][n+1] = {0};
    for ( int i=0; i<m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // Space O(N x N) #Expensive
    // For Weighted Grapgh adj[u][v] = Weight;

    //------------------------------------------------//
    
    // Adjacency List Method :

    vector<int> adjL[n+1];
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    // Space O(E)
    // For Weighted Grapgh use Pairs vector<pair<int, int>> adjL[n+1];
}