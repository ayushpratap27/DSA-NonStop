#include<bits/stdc++.h>
using namespace std;

//        Memoization solution is giving run time error because of constraints

//        Tabulation Solution

int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
                int len = 0 + dp[ind + 1][prev_ind + 1];
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + dp[ind + 1][ind + 1]);
                }

                dp[ind][prev_ind+1] = len;
            }
        }

        return dp[0][-1+1];
}

//          Space Optimised

int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);

        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=n-1;prev_ind>=-1;prev_ind--){
             int len = 0 + next[prev_ind + 1];
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + next[ind + 1]);
                }

                curr[prev_ind+1] = len;
            }
            next = curr;
        }

        return next[-1+1];
}


//         Optimised Tabulation

int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, 1);

    int maxi = 1;
    for(int ind=0;ind<n;ind++){
        for(int prev=0;prev<ind;prev++){
            if(nums[prev] < nums[ind]){
                dp[ind] = max(1+dp[prev], dp[ind]);
            }
        }

        maxi = max(dp[ind], maxi);
    }

    return maxi;
}