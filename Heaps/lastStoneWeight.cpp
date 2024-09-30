#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones){
    priority_queue<int> pq;
    int n = stones.size();

    for (int i = 0; i < n; i++){
        pq.push(stones[i]);
    }

    while (pq.size() > 1){
        int stone1 = pq.top();
        pq.pop();
        int stone2 = pq.top();
        pq.pop();

        int weight = stone1 - stone2;
        if (weight)
            pq.push(stone1 - stone2);
    }
    if (pq.empty())
        return 0;

    return pq.top();
}