#include<bits/stdc++.h>
using namespace std;


bool dfs(int node,vector<int> adj[],int vis[],int pathVis[]){
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for(auto it : adj[node]){
        // when the node is not visited
        if(!vis[it]){
            if(dfs(it,adj,vis,pathVis) == true){
                return true;
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            else if(pathVis[it]){
                return true;
            }
        }
    }

    pathVis[node] = 0;
    return false;
}

bool isCyclic(int v,vector<int> adj[]){
    int vis[v] = {0};
    int pathVis[v] = {0};

    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis) == true)
            return true;
        }
    }

    return false;

}

// T.C. = O(v + e) as it is directed path
// S.C. = O(2n)


//********************Using BFS - toposort*********************

bool isCyclic(int v,vector<int>adj[]){
    int indegree[v] = {0};
    for(int i=0;i<v;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(cnt == v) return false;

    return true;
}

/*
The time complexity of the isCyclic function is O(V + E), where V is the number of vertices 
and E is the number of edges in the graph. This is because we are iterating through all the vertices 
and edges in the graph to calculate the indegree of each vertex and then perform a topological sort 
using a queue.

The space complexity is O(V) for the indegree array and the queue used for the topological sort.
*/