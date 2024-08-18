#include<bits/stdc++.h>
using namespace std;

//           Tabulation

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= k; cap++) {  
                if(buy) {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
                } else {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                }
            }
        }
    }

    
    return dp[0][1][k];
}


//           Memoization
int f(int ind, int tranNo, vector<int> &prices, int k, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind == n || tranNo == 2*k) return 0;

        if(dp[ind][tranNo] != -1) return dp[ind][tranNo];

        if(tranNo%2 == 0){
            return dp[ind][tranNo] = max(-prices[ind] + f(ind+1,tranNo+1,prices,k,dp), 0 + f(ind+1,tranNo, prices, k, dp));
        }else{
            return dp[ind][tranNo] = max(prices[ind] + f(ind+1,tranNo+1,prices,k,dp), 0 + f(ind+1,tranNo, prices, k, dp));
        }
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2*k, -1));

    return f(0, 0, prices, k, dp);
}

//              Tabulation
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

    for(int ind=n-1;ind>=0;ind--){
        for(int tranNo=2*k-1;tranNo>=0;tranNo--){
            if(tranNo%2 == 0){
                dp[ind][tranNo] = max(-prices[ind] + dp[ind+1][tranNo+1], 0 + dp[ind+1][tranNo]);
            }else{
                dp[ind][tranNo] = max(prices[ind] + dp[ind+1][tranNo+1], 0 + dp[ind+1][tranNo]);
            } 
        }
    }
    return dp[0][0];
}

//            Space Optimised
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int> after(2*k+1, 0), curr(2*k+1, 0);

    for(int ind=n-1;ind>=0;ind--){
        for(int tranNo=2*k-1;tranNo>=0;tranNo--){
            if(tranNo%2 == 0){
                curr[tranNo] = max(-prices[ind] + after[tranNo+1], 0 + after[tranNo]);
            }else{
                curr[tranNo] = max(prices[ind] + after[tranNo+1], 0 + after[tranNo]);
            } 
        }

        after = curr;
    }
    return after[0];
}