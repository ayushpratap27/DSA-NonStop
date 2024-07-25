#include<bits/stdc++.h>
using namespace std;

// using memoization
int f(int idx, vector<int> &heights, vector<int> &dp){
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int left = f(idx-1,heights,dp) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;
    if(idx > 1)
    right = f(idx-2,heights,dp) + abs(heights[idx] - heights[idx-2]);

    return dp[idx] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}

// T.C. = O(n)
// S.C. = O(n) + o(n)