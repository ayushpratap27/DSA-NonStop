#include<bits/stdc++.h>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n=nums.size();
    vector<int> result(n,0);

    vector<int> sortedNums(nums);
    sort(sortedNums.begin(),sortedNums.end());
    for(int i=0;i<n;i++){
        auto it = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]);
        result[i] = distance(sortedNums.begin(), it);
    }

    return result;
}