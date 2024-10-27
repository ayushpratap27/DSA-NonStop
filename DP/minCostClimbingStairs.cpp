#include<bits/stdc++.h>
using namespace std;


//           Memoization
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

//          Tabulation

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int>dp(n+1, 0);
        
    for(int i=2; i<=n; i++){
        int mini = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);

        dp[i] = mini;
    }

    return dp[n];
        
}