#include <bits/stdc++.h>
using namespace std;


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    int vis[n]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }

    return bfs;
}

/*
Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
This is because in the worst case scenario, we visit each vertex and each edge once during the BFS 
traversal.

Space complexity: O(V), where V is the number of vertices in the graph. This is because we are using 
a queue to store the vertices to be visited, and in the worst case scenario, the queue can contain all 
the vertices in the graph.
*/