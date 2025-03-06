#include<bits/stdc++.h>
using namespace std;

//         Recursive Solution
int f(int ind, int sum, vector<int> & arr){
	if(sum == 0) return 1;
	if(ind == 0) return (arr[0] == sum);

	int notTake = f(ind-1, sum, arr);
	int take = 0;
	if(arr[ind] <= sum) take = f(ind-1, sum-arr[ind], arr);

	return take + notTake;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	return f(n-1, k, arr);
}

//             Memoization
int mod = 1e9 + 7;

int f(int ind, int sum, vector<int> & arr, vector<vector<int>> &dp){
	if(ind == 0){
		if(sum == 0 && arr[0] == 0) return 2;
		if(sum == 0 || sum == arr[0]) return 1;
		return 0;
	}

	if(dp[ind][sum] != -1) return dp[ind][sum];

	int notTake = f(ind-1, sum, arr, dp);
	int take = 0;
	if(arr[ind] <= sum) take = f(ind-1, sum-arr[ind], arr, dp);

	return dp[ind][sum] = (take + notTake)%mod;
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));

	return f(n-1, k, arr, dp);
}

//              Tabulation
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	for(int i=0;i<n;i++){
		dp[i][0] = 1;
	}
	if(arr[0] <= k) dp[0][arr[0]] = 1;
	for(int ind=1;ind<n;ind++){
		for(int sum=0;sum<=k;sum++){
			int notTake = dp[ind-1][sum];
			int take = 0;
			if(arr[ind] <= sum) take = dp[ind-1][sum-arr[ind]];
			dp[ind][sum] = (take + notTake)%mod;
		}
	}

	return dp[n-1][k];
}
