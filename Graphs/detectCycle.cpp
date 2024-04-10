#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    bool isCyclicUtil(int v, bool visited[], int parent, vector<int> adj[]) {
        visited[v] = true; 

            for (int i = 0; i < adj[v].size(); i++) {
            int adjNode = adj[v][i];
            if (!visited[adjNode]) {
                if (isCyclicUtil(adjNode, visited, v, adj))
                    return true;
            }
            else if (adjNode != parent)
                return true;
        }
        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        bool visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, -1, adj))
                    return true; 
            }
        }
        return false; 
    }
};