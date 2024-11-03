#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int ind=1;ind<n;ind++){
        for(int target = 1;target<=k;target++){

            bool notTake = dp[ind-1][target];
            bool take = false;  
            if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];

            dp[ind][target] = take | notTake;
        }
    }

    return dp[n-1][k];

}

bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    for(int i=0;i<nums.size();i++) totalSum += nums[i];

    if(totalSum%2 != 0) return false;
    int target = totalSum/2;

    return subsetSumToK(nums.size(), target, nums);

}