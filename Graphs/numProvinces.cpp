#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> &adjList, vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adjList[node]) {
        if (!vis[it]) {
            dfs(it, adjList, vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> vis(n, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, adjList, vis);
        }
    }

    return cnt;
}
//  T.C. = O(n)[loop] + O(V+2E)[dfs] = O(n)
//  S.C. = O(n)[vis array] + O(n)[recursion stack]
