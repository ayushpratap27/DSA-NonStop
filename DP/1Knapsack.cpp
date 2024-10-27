#include <bits/stdc++.h> 
using namespace std;

//          Memoization 
int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
	if(ind == 0){
		if(wt[0] <= W) return val[0];
		return 0;
	}

	if(dp[ind][W] != -1) return dp[ind][W];

	int notTake = 0 + f(ind-1, W, wt, val, dp);
	int take = INT_MIN;
	if(wt[ind] <= W) take = val[ind] + f(ind-1, W-wt[ind], wt, val, dp);

	return dp[ind][W] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return f(n-1, maxWeight, weight, value, dp);
}

//              Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

	for(int wt=weight[0]; wt<=maxWeight; wt++) dp[0][wt] = value[0];

	for(int ind=1;ind<n;ind++){
		for(int wt=0;wt<=maxWeight;wt++){
			int notTake = 0 + dp[ind-1][wt];
			int take = INT_MIN;
			if(weight[ind] <= wt) take = value[ind] + dp[ind-1][wt-weight[ind]];

			dp[ind][wt] = max(take,notTake);
		}
	}

	return dp[n-1][maxWeight];
}