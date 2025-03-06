#include<iostream>
#include<vector>
using namespace std;

int countSetBits(int n){
    return __builtin_popcount(n);
}

vector<int> sortByBits(vector<int> &arr){
    int n = arr.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto it : arr){
        int val = countSetBits(it);
        pq.push({val, it});
    }

    int idx = 0;
    while (!pq.empty()){
        arr[idx] = pq.top().second;
        pq.pop();
        idx++;
    }
    return arr;
}