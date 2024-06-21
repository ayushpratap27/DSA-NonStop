#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, check) == true) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;

}

bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, adj, vis, pathVis, check) == true) {
                check[node] = 0;
                return true;
            }
        } else if (pathVis[it]) {
            check[node] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0;

    return false;

}

/*
The time complexity of this solution is O(V + E), where V is the number of vertices and 
E is the number of edges in the graph. This is because the DFS algorithm visits each 
vertex and each edge exactly once.

The space complexity is O(V), where V is the number of vertices in the graph. This is 
because we are using arrays of size V to keep track of visited nodes, nodes in the 
current path, and nodes that have been checked.
*/

//**********************Using TOPO sort ********************/
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n,0);
        vector<int> adjRev[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int v = graph[i][j];
                adjRev[v].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> safeNode;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNode.push_back(node);

            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(safeNode.begin(),safeNode.end());

        return safeNode;
}

/*
The time complexity of this solution is O(V + E), where V is the number of nodes and E 
is the number of edges in the graph. This is because we iterate through all the nodes 
and edges in the graph to calculate the indegree of each node and build the reverse 
adjacency list.

The space complexity is also O(V + E) because we use additional space to store the indegree 
of each node, the reverse adjacency list, and the queue for BFS traversal.
*/