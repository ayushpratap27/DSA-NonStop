#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
    vis[node] = 1;
    storeDfs.push_back(node);
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, storeDfs);
        }
    }
}

vector<int>dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> storeDfs;
    vector<int> vis(V+1, 0);
    for(int i = 1; i <= V; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, storeDfs);
        }
    }
    return storeDfs;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V+1];   
    
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = dfsOfGraph(V, adj);
    
    for(auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}