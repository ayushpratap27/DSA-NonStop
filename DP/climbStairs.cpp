#include<iostream>
#include<vector>
using namespace std;

int f(int idx, vector<int> &dp){
        if(idx == 0) return 1;
        if (idx == 1)
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        int left = f(idx - 1, dp);
        int right = f(idx - 2, dp);

        return dp[idx] = left + right;
}

int climbStairs(int n){
    vector<int> dp(n + 1, -1);

    return f(n, dp);
}

//   Tabulation approach

int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
}