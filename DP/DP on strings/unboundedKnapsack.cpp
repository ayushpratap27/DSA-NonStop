#include<bits/stdc++.h>
using namespace std;

//                Memoization
int f(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(ind == 0){
        return ((int)(w/weight[0])) * profit[0];
    }

    if(dp[ind][w] != -1) return dp[ind][w];

    int notTake = 0 + f(ind-1, w, profit, weight, dp);
    int take = 0;
    if(weight[ind] <= w) take = profit[ind] + f(ind, w-weight[ind], profit, weight, dp);

    return dp[ind][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return f(n-1, w, profit, weight, dp);
}

//               Tabulation Solution
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for(int W=0;W<=w;W++){
        dp[0][W] = ((int)(W / weight[0])) * profit[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int notTake = 0 + dp[ind-1][W];
            int take = 0;
            if(weight[ind] <= W) take = profit[ind] + dp[ind][W-weight[ind]];

            dp[ind][W] = max(take, notTake);
        }
    }

    return dp[n-1][w];
}