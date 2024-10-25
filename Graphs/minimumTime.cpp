#include<iostream>
#include<vector>
using namespace std;

vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    vector<vector<pair<int,int>>>v(n);
        
    int i;
    for(i=0;i<edges.size();i++){
        v[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        v[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
        
    vector<int>dis(n,INT_MAX);
    dis[0]=0;
    while(pq.size()){
        int s1=pq.top().first;
        int s2=pq.top().second;
        
        pq.pop();
        if(dis[s2]<s1)continue;
        for(auto x:v[s2]){
                if(x.second+s1 < dis[x.first] && disappear[x.first]>x.second+s1){
                    dis[x.first]=x.second+s1;
                    pq.push({x.second+s1,x.first});
                }
        }
        
    }
    for(i=0;i<n;i++){
        if(dis[i]==INT_MAX)dis[i]=-1;
    }
    return dis;
}