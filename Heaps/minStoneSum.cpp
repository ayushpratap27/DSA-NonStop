#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k){
    priority_queue<int> pq(piles.begin(), piles.end());

    for (int i = 0; i < k; i++){
        int top = pq.top();
        pq.pop();
        top = top - floor(top / 2);
        pq.push(top);
    }

    int totalStones = 0;
    while (!pq.empty()){
        totalStones += pq.top();
        pq.pop();
    }

    return totalStones;
} 
// Time Complexity: O(n log n) due to priority queue operations
// Space Complexity: O(n) for storing the elements in the priority queue
