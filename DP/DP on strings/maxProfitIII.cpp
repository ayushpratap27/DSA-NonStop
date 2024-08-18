#include<bits/stdc++.h>
using namespace std;

//           Memoization
int f(int ind , int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(cap == 0) return 0;
        if(ind == n) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if(buy){
            return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0,cap,prices,dp), 0 + f(ind+1,1,cap,prices,dp));
        }else{
            return dp[ind][buy][cap] = max(prices[ind] + f(ind+1,1,cap-1,prices,dp), f(ind+1,0,cap,prices,dp));
        }

}

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0,1,2,prices,dp);
}


//                   Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    // for(int ind=0;ind<n;ind++){
    //     for(int buy=0;buy<=1;buy++){
    //         dp[ind][buy][0] = 0;
    //     }
    // }

    // for(int buy=0;buy<=1;buy++){
    //     for(int cap=0;cap<=2;cap++){
    //         dp[n][buy][cap] = 0;
    //     }
    // }


    // No need for the first two initialization loops since the dp array is already initialized to 0.

    // Fill the dp array
    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {  // cap should start from 1 since cap = 0 is already handled
                if(buy) {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
                } else {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                }
            }
        }
    }

    // The answer is stored in dp[0][1][2], which represents starting with the ability to buy, and 2 transactions remaining
    return dp[0][1][2];

}


//      Space optimized

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(3, 0)), curr(2, vector<int>(3,0));

    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {  
                if(buy) {
                    curr[buy][cap] = max(-prices[ind] + after[0][cap], after[1][cap]);
                } else {
                    curr[buy][cap] = max(prices[ind] + after[1][cap-1], after[0][cap]);
                }
            }
        }
        after = curr;
    }

    
    return after[1][2];
}