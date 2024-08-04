#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, auto k) {
    unordered_map<int,int>mpp;
    vector<int>ans;
    for(auto ele:nums){
        mpp[ele]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto it:mpp){
        pq.push({it.second,it.first});
    }
    while(k){
        ans.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    
    return ans;
}