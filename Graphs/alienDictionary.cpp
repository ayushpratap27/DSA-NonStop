#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int v, vector<int> adj[]){
    int indegree[v] = {0};
    for(int i=0;i<v;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    return topo;
}


string findOrder(string dict[],int N,int K){
    vector<int> adj[K];
    for(int i=0;i<N-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(),s2.size());

        for(int ptr=0;ptr<len;ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr]  - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K,adj);
    string ans = "";
    for(auto it : topo){
        ans = ans + char(it - 'a');
    }

    return ans;
}

/*
The time complexity of the given code is O(N + K) where N is the number of words in the dictionary 
and K is the number of unique characters in the dictionary. This is because we are iterating through 
all the words in the dictionary to build the adjacency list and then performing a topological sort on 
the graph represented by the adjacency list.

The space complexity of the given code is O(K) where K is the number of unique characters in the 
dictionary. This is because we are storing the adjacency list for each character in the dictionary.

Overall, the time complexity is linear with respect to the number of words and characters in the 
dictionary, and the space complexity is linear with respect to the number of unique characters in 
the dictionary.
*/





// Cases when the ordering is not possible
// 1) a b c d
//    a b c
// if everything is matching and the larger string is before the smaller string 

// 2) a b c 
//    b a t
//    a d e
// When their is cyclic dependency