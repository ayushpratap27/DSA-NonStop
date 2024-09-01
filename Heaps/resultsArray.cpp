#include<bits/stdc++.h>
using namespace std;

vector<int> resultsArray(vector<vector<int>>& queries, int k) {
    priority_queue<int> pq;
    vector<int> result;

    for(auto& query : queries){
        int distance = abs(query[0]) + abs(query[1]);
        pq.push(distance);

        if(pq.size() > k)pq.pop();

        int ans = pq.size() < k ? -1 : pq.top();
        result.push_back(ans);
    }

    return result;
}