#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(v);
    for (const auto& pair : prerequisites) {
        adj[pair[1]].push_back(pair[0]);
    }

    vector<int> indegree(v, 0);
    for (int i = 0; i < v; ++i) {
        for (int node : adj[i]) {
            indegree[node]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (topo.size() == v) {
        return topo;
    } else {
        return {};
    }
}

/*
The time complexity of this algorithm is O(V + E), where V is the number of vertices and 
E is the number of edges in the graph. This is because we iterate through all the vertices 
and edges in the graph to calculate the indegree of each node and perform topological 
sorting using a queue.

The space complexity of this algorithm is O(V), where V is the number of vertices in the graph.
This is because we use additional space to store the adjacency list, indegree array, queue, 
and the resulting topological order.
*/