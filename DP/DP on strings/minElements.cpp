#include <bits/stdc++.h> 
using namespace std;

//         Memoization
int f(int ind, int T, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0){
        if(T % coins[0] == 0) return T/coins[0];
        return INT_MAX;
    }

    if(dp[ind][T] != -1) return dp[ind][T];

    int notTake = 0 + f(ind-1, T, coins, dp);
    int take = INT_MAX;
    if(coins[ind] <= T){
        int res = f(ind, T - coins[ind], coins, dp);
        if(res != INT_MAX) {
            take = 1 + res;
        }
    }
    return dp[ind][T] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n-1, amount, coins, dp);

    if(ans == INT_MAX) return -1;
    return ans;
}

//               Tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for(int T=0; T<=amount; T++){
        if(T % coins[0] == 0) dp[0][T] = T/coins[0];
        else dp[0][T] = INT_MAX;
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= amount; T++){
            int notTake = dp[ind-1][T];
            int take = INT_MAX;
            if(coins[ind] <= T){
                int res = dp[ind][T-coins[ind]];
                if(res != INT_MAX) take = 1 + res;
            }
            dp[ind][T] = min(take,notTake);
        }
    }
    int ans = dp[n-1][amount];

    if(ans == INT_MAX) return -1;
    return ans;
}