#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &component){
    vis[node] = true;
    component.push_back(node);
    for (auto i : adj[node]){
        if (!vis[i]){
            dfs(i, vis, adj, component);
        }
    }
}

bool isCompleteComponent(const vector<int> &component, const vector<vector<int>> &adj){
    int k = component.size();
    int edgeCount = 0;

    for (int node : component){
        edgeCount += adj[node].size();
    }

    edgeCount /= 2;

    return edgeCount == k * (k - 1) / 2;
}

int countCompleteComponents(int n, vector<vector<int>> &edges){
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    int cnt = 0;

    for (const auto &it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for (int i = 0; i < n; ++i){
        if (!vis[i]){
            vector<int> component;
            dfs(i, vis, adj, component);
            if (isCompleteComponent(component, adj))
            {
                cnt++;
            }
        }
    }

    return cnt;
}