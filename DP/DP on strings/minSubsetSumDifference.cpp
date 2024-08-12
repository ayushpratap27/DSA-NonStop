#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& nums, int n)
{
	int totalSum = 0;
    for(int i=0;i<nums.size();i++) totalSum += nums[i];

    int k = totalSum;
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int i=0;i<n;i++) dp[i][0] = true;
    if(nums[0] <= k) dp[0][nums[0]] = true;

    for(int ind=1;ind<n;ind++){
        for(int target = 1;target<=k;target++){

            bool notTake = dp[ind-1][target];
            bool take = false;
            if(nums[ind] <= target) take = dp[ind-1][target-nums[ind]];

            dp[ind][target] = take | notTake;
        }
    }

    int mini = 1e9;
    for(int s1=0;s1<=totalSum/2;s1++){
        if(dp[n-1][s1] == true){
            int s2 = totalSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}