#include<bits/stdc++.h>
using namespace std;

bool check(int start, int V, vector<int> adj[], int color[]) {
    queue<int> q;
    q.push(start);
    color[start]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            } else if(color[it] == color[node]) {
                return false;
            }
        }
    }
    return true; 
}

bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){ 
            int v=graph[i][j];
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
    }

    int color[n];
    for(int i=0;i<n;i++)
        color[i]=-1;

    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(check(i, n, adj, color) == false){
                return false;
            }
        }
    }

    return true;
}