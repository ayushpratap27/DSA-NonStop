#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>> &adj, vector<int> &vis){
    vis[start] = 1;
    for (auto &it : adj[start]){
        if (!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms){
    int n = rooms.size();
    int m = rooms[0].size();
    vector<int> vis(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++){
        for (auto &key : rooms[i]){
            adj[i].push_back(key);
        }
    }

    dfs(0, adj, vis);

    for (int i = 0; i < n; i++){
        if (vis[i] != 1){
            return false;
        }
    }

    return true;
}