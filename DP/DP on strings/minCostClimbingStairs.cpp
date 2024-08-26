#include<bits/stdc++.h>
using namespace std;

int f(int i, vector<int> &cost, vector<int> &dp){
    if(i<=1) return 0;
    if(dp[i] != -1) return dp[i];
    int mini = min(cost[i-1] + f(i-1,cost, dp), cost[i-2] + f(i-2, cost, dp));

    return dp[i] = mini;
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int>dp(n+1, -1);

    return f(n, cost, dp);
        
}