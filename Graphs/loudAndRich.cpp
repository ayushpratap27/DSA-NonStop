#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &answer, vector<int> &quiet){
    vis[node] = 1;
    for (int it : adj[node]){
        if (!vis[it]){
            dfs(it, adj, vis, answer, quiet);
        }
        if (quiet[answer[it]] < quiet[answer[node]]){
            answer[node] = answer[it];
        }
    }
}

vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet){
    int n = quiet.size();
    vector<vector<int>> adj(n);

    for (auto &r : richer){
        adj[r[1]].push_back(r[0]); // r[1] is poorer, r[0] is richer
    }

    vector<int> answer(n);
    for (int i = 0; i < n; i++){
        answer[i] = i;
    }

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, adj, vis, answer, quiet);
        }
    }

    return answer;
}