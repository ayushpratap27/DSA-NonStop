#include<bits/stdc++.h>
using namespace std;


void topoSort(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        int v = it.first;
        if(!vis[v]){
            topoSort(v,adj,vis,st);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int N,int M,vector<int> edges[]){
    vector<pair<int, int>> adj[N];
    for(int i=0;i<M;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt});
    }

    int vis[N] = {0};
    stack<int> st;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            topoSort(i,adj,vis,st);
        }
    }

    vector<int> dist(N);
    for(int i=0;i<N;i++){
        dist[i] = 1e9;
    }
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
 
    }

    return dist;
}

/*
The time complexity of the given code is O(N + M), where N is the number of nodes and M is the number 
of edges in the graph. This is because we are performing a topological sort on the graph, which has a 
time complexity of O(N + M) due to the DFS traversal. Additionally, we are updating the distances for 
each node in the graph, which also takes O(N + M) time.

The space complexity of the given code is O(N) for the adjacency list, O(N) for the visited array, 
O(N) for the stack, and O(N) for the distance array. Therefore, the overall space complexity is O(N).

The time complexity is O(N + M) because we are visiting each node and edge once during the topological 
sort and distance calculation. The space complexity is O(N) because we are storing information for each 
node in the graph.
*/