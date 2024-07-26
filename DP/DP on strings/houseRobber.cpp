#include<bits/stdc++.h>
using namespace std;

// using recursion
int f(int ind, vector<int> &nums){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    int pick = nums[ind] + f(ind - 2, nums);
    int notPick = 0 + f(ind - 1, nums);

    return max(pick, notPick);
}
// T.C. = (2^n)

// Using memoization
int f(int idx, vector<int> &nums, vector<int> &dp){
    if(idx == 0) return nums[idx];
    if(idx < 1) return 0;

    if(dp[idx] != -1) return dp[idx];
    int pick = nums[idx] + f(idx-2, nums, dp);
    int nonPick = 0 + f(idx-1, nums, dp);

    return dp[idx] = max(pick, nonPick);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);

    return f(n-1, nums, dp);
}

// T.C. = O(n)    S.C. = O(n) + O(n)

// using tabulation
int rob(vector<int>& nums) {
    int n = nums.size();
    
    int dp[n] = {0};
    dp[0] = nums[0];
    int neg = 0;

    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i > 1) take += dp[i-2];
        int nonTake = 0 + dp[i-1];

        dp[i] = max(take, nonTake);
    }

    return dp[n-1];
}

// T.C. = O(n)  S.C. = O(n) 

// Space optimisation

int rob(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int nonTake = 0 + prev;

        int curr_i = max(take, nonTake);
        prev2 = prev;
        prev = curr_i;

    }
    return prev;
}
// T.C. = O(n)   S.C. = O(1)

// Using memoization
int f(int idx, vector<int> &nums, vector<int> &dp){
    if(idx < 0) return 0;
    if(idx == 0) return nums[idx];

    if(dp[idx] != -1) return dp[idx];
    int pick = nums[idx] + f(idx-2, nums, dp);
    int nonPick = 0 + f(idx-1, nums, dp);

    return dp[idx] = max(pick, nonPick);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;

    vector<int> dp(n, -1);

    return f(n-1, nums, dp);
}

// Space optimisation

int rob(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return 0;

    int prev = nums[0];
    int prev2 = 0;

    for(int i=2;i<=n;i++){
        int take = nums[i-1];
        if(i > 2) take += prev2;
        int nonTake = 0 + prev;

        prev2 = prev;
        prev = max(take, nonTake);
    }
    return prev;
}