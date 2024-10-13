#include <bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> &nums){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = nums.size();
    int mini, maxi = INT_MIN;
    for (int i = 0; i < n; i++){
        pq.push(make_pair(nums[i][0], make_pair(i, 0)));
        maxi = max(maxi, nums[i][0]);
    }

    mini = pq.top().first;
    vector<int> ans(2);
    ans[0] = mini;
    ans[1] = maxi;
    pair<int, pair<int, int>> temp;
    int row, col, ele;

    while (pq.size() == nums.size()){
        temp = pq.top();
        pq.pop();
        ele = temp.first;
        row = temp.second.first;
        col = temp.second.second;

        if (col + 1 < nums[row].size()){
            col++;
            pq.push(make_pair(nums[row][col], make_pair(row, col)));
            maxi = max(maxi, nums[row][col]);
            mini = pq.top().first;

            if (maxi - mini < ans[1] - ans[0]){
                ans[0] = mini;
                ans[1] = maxi;
            }
        }
    }

    return ans;
}   
