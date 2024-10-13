#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    
    int n = arr.size();
    vector<pair<int, pair<int, int>>> temp;

    for (int i = 0; i < K; i++) {
        temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq(temp.begin(), temp.end());

    vector<int> ans;
    int val = 0;
    int i, j;
    pair<int, pair<int, int>> element;

    while (!pq.empty()) {
        element = pq.top();
        pq.pop();
        val = element.first;
        i = element.second.first;
        j = element.second.second;

        ans.push_back(val);

        if (j + 1 < K) {
            pq.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
        }
    }

    return ans; 
} 

