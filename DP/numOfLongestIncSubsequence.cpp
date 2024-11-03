#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);

        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }

            maxi = max(maxi, dp[i]);
        }

        int numbers = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi) numbers += cnt[i];
        }

        return numbers;
}