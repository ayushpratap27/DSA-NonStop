#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (const auto& pair : prerequisites) {
        adj[pair[1]].push_back(pair[0]);
    }

    vector<int> indegree(numCourses, 0);
    for(int i=0;i<numCourses;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }

    }

    if(topo.size() == numCourses) return true;

    return false;
}

/*
The time complexity of this code is O(V + E), where V is the number of courses and E is the number 
of prerequisites. This is because we are performing a topological sort using Kahn's algorithm, which 
involves iterating through all the vertices and edges in the graph.

The space complexity is also O(V + E) because we are using adjacency lists to represent the graph, 
as well as maintaining arrays for indegrees and the topological ordering.
*/