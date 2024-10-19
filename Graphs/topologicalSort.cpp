#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for (auto it : adj[node]){
        if (!vis[it]){
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &adj){

    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int> topoSort;
    while (!st.empty()){
        topoSort.push_back(st.top());
        st.pop();
    }

    return topoSort;
}
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for (auto it : adj[node]){
        if (!vis[it]){
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int> topoSort;
    while (!st.empty()){
        topoSort.push_back(st.top());
        st.pop();
    }

    return topoSort;
}