#include<bits/stdc++.h>
using namespace std;

//********** Using BFS ***********
bool check(int start, vector<int> adj[], int color[]) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }

        return true;
}

//******************* Using DFS ********************
bool dfs(int node,int col,int color[],vector<int> adj[]){
    color[node] = col;
    for(auto it : adj[node]){
        if(color[it] == -1){
            if(!dfs(it,!col,color,adj)){
                return false;
            }else if(color[it] == col){
                return false;
            }
        }
    }

    return true;
}
// T.C. & S.C. is same as DFS algorithm


bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return true;

        vector<int> adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int v = graph[i][j];
                adj[i].push_back(v);
                adj[v].push_back(i);  
            }
        }

        int color[n];
        for(int i=0;i<n;i++){
            color[i] = -1;
        }

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if (!check(i, adj, color)){
                    return false;
                }
            }
        }

        return true;
}


/*
The time complexity of this solution is O(V + E), where V is the number of vertices
in the graph and E is the number of edges. This is because the dfs function visits each
vertex and each edge exactly once.

The space complexity is O(V), where V is the number of vertices in the graph. This is because 
we are using two arrays of size V (visited and color) to keep track of visited vertices and their colors.
*/