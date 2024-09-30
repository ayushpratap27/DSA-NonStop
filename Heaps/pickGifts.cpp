#include <bits/stdc++.h>
using namespace std;

long long pickGifts(vector<int> &gifts, int k){
    priority_queue<int> pq;
    int n = gifts.size();

    for (int i = 0; i < n; i++){
        pq.push(gifts[i]);
    }

    while (k--){
        int gift = pq.top();
        pq.pop();
        pq.push(floor(sqrt(gift)));
    }

    long long totalGift = 0;
    while (!pq.empty()){
        totalGift += pq.top();
        pq.pop();
    }

    return totalGift;
}