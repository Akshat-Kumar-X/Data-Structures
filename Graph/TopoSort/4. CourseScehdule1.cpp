#include <bits/stdc++.h>
using namespace std;

// BFS or DFS approach
// Time: O(v + E)
// Space: O(V + E)

//BFS
// Simple BFS with a inDegree arr , processing nodes with 0 indegree and removing them.
// after removing them updating the inDegree of their adj Nodes and repeating process.
// if all notes not processed then Loop found return false;


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;

    vector<int> inDegree(n, 0);
    vector<vector<int>> adj(n);  // Adjacency list to store dependencies

    // Construct adjacency list and in-degree count
    for (auto it: prerequisites) {
        int course = it[0];
        int prereq = it[1];
        adj[prereq].push_back(course);  // Directed edge: prereq -> course
        inDegree[course]++;  // Increase in-degree of the course
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) { 
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (auto neighbor: adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return count == n;  // If all courses are processed, return true
}

//DFS:
// keeping Track of Visited Paths in DFS calls, marking unVistited Paths once backtracked
// if node is already visited and that Path is also already Visted then loop found


bool helper(int node, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& adj) {
    vis[node] = 1;
    pathvis[node] = 1;  // Mark the current node as part of the path

    for (auto v : adj[node]) {
        if (!vis[v]) {  // If not visited, do a DFS
            if (helper(v, vis, pathvis, adj)) 
                return true; // Cycle detected
        } 
        else if (pathvis[v]) { // If already in the current path, cycle exists
            return true;
        }
    }

    pathvis[node] = 0;  // Backtrack: remove from path
    return false;
}

bool canFinish(int n, vector<vector<int>>& nums) {
    vector<vector<int>> adj(n);
    
    // **Fix: Correct edge direction**
    for (auto path : nums) {
        int u = path[0], v = path[1]; 
        adj[v].push_back(u);  // `v` must be completed before `u`
    }

    vector<int> vis(n, 0);
    vector<int> pathvis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i] && helper(i, vis, pathvis, adj)) 
            return false;  // If a cycle is found, courses can't be completed
    }

    return true;  // No cycle detected, all courses can be finished
}

    