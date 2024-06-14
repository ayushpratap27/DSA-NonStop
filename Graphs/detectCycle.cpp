#include<bits/stdc++.h>
using namespace std;

//*********** Using BFS ************/
bool detect(int src,vector<int> adj[],int vis[]){
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src,-1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push({adjNode,node});
            }else if(parent != adjNode){
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V,vector<int> adj[]){
    int vis[V];
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)){
                return true;
            }
        }
    }

    return false;
}

//  T.C. = O(N + 2E) + O(N)
//  S.C. = O(N)

// Summation(adjacent node) = summation(degree) = 2E(undirected)
//                                              = E(directed)




//************* Using BFS **************/
bool dfs(int node,int parent,int vis[],vector<int> adj[]){
    vis[node] = 1;
    for(auto adjNode : adj[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode,node,vis,adj) == true){
                return true;
            }
        }else if(parent != adjNode){
            return true;
        }
    }

    return false;
}


bool detectCycle(int v,vector<int> adj[]){
    int vis[v] = {0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj) == true){
                return true;
            }
        }
    }

    return false;

}