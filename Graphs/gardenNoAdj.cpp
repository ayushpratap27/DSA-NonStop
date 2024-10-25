#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans){
    vis[node] = 1;

    for (int color = 1; color <= 4; color++){
        bool isColorAvailable = true;

        for (int neighbor : adj[node]){
            if (ans[neighbor] == color){
                isColorAvailable = false;
                break;
            }
        }

        if (isColorAvailable){
            ans[node] = color;
            return;
        }
    }

    for (auto it : adj[node]){
        if (!vis[it]){
            dfs(it, adj, vis, ans);
        }
    }
}

vector<int> gardenNoAdj(int n, vector<vector<int>> &paths){
    vector<vector<int>> adj(n);
    for (auto it : paths){
        adj[it[0] - 1].push_back(it[1] - 1);
        adj[it[1] - 1].push_back(it[0] - 1);
    }

    vector<int> vis(n, 0);
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, adj, vis, ans);
        }
    }
    return ans;
}