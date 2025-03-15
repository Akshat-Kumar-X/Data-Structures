#include <bits/stdc++.h>
using namespace std;

// Litreally Just Kahn's Algo

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;

    vector<int> inDegree(n, 0);
    vector<vector<int>> adj(n);
    
    for (auto it: prerequisites) {
        int course = it[0];
        int prereq = it[1];
        adj[prereq].push_back(course);   
        inDegree[course]++; 
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) { 
            q.push(i);
        }
    }

    vector<int> result;
    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        count++;

        for (auto neighbor: adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    if (count == n)
        return result;
    return {};
}