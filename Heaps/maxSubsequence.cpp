#include <iostream>
#include <vector>
using namespace std;

static bool cmpfun(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

vector<int> maxSubsequence(vector<int> &nums, int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < nums.size(); i++){
        pq.push({nums[i], i});
        if (pq.size() > k)
            pq.pop();
    }

    vector<pair<int, int>> vec;
    while (!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end(), cmpfun);

    vector<int> ans;
    for (auto ele : vec){
        ans.push_back(ele.first);
    }

    return ans;

    // while (k) {
    //     ans[pq.top().second] = pq.top().first;
    //     pq.pop();
    //     k--;
    // }

    // vector<int> result(k);
    // for (int i = 0; i < nums.size(); i++) {
    //     if (ans[i] != INT_MIN)
    //         result.push_back(ans[i]);
    // }

    // return result;
}