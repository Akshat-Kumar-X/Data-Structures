#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

void linkStateRouting(int numRouters, vector<vector<int>> &connections) {
    vector<vector<pair<int, int>>> graph(numRouters);

    // Build the graph
    for (auto &conn : connections) {
        int src = conn[0], dest = conn[1], weight = conn[2];
        graph[src].emplace_back(weight, dest);
        graph[dest].emplace_back(weight, src);
    }

    // Calculate shortest path for each router using Dijkstra's algorithm
    for (int router = 0; router < numRouters; router++) {
        vector<int> distances(numRouters, INF);
        distances[router] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, router);

        while (!pq.empty()) {
            auto [currentDistance, currentRouter] = pq.top();
            pq.pop();

            for (auto &[weight, neighbor] : graph[currentRouter]) {
                int newDistance = currentDistance + weight;
                if (newDistance < distances[neighbor]) {
                    distances[neighbor] = newDistance;
                    pq.emplace(newDistance, neighbor);
                }
            }
        }

        // Print shortest paths
        cout << "\nRouter " << router << " Shortest Path Table: ";
        for (int i = 0; i < numRouters; i++) {
            cout << (distances[i] == INF ? "INF" : to_string(distances[i])) << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRouters, numConnections;
    cout << "Enter the number of routers: ";
    cin >> numRouters;

    cout << "Enter the number of connections: ";
    cin >> numConnections;

    vector<vector<int>> connections(numConnections, vector<int>(3));
    for (int i = 0; i < numConnections; i++) {
        cout << "Enter source, destination, and weight for connection " << i + 1 << ": ";
        cin >> connections[i][0] >> connections[i][1] >> connections[i][2];
    }

    cout << "\n--- Link State Routing ---\n";
    linkStateRouting(numRouters, connections);

    return 0;
}
