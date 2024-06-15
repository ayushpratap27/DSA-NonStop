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