#include<iostream>
#include<vector>
using namespace std;


// Memoization approach
int solve(int idx, vector<int>& arr, int k, vector<int> &dp) {
    int n = arr.size();
    if (idx == n)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    int len = 0;
    int maxi = INT_MIN;
    int maxSum = INT_MIN;
    for (int i = idx; i < min(n, idx + k); i++){
        len++;
        maxi = max(maxi, arr[i]);
        int sum = len * maxi + solve(i + 1, arr, k, dp);
        maxSum = max(maxSum, sum);
    }

    return dp[idx] = maxSum;
}

int maxSumAfterPartitioning(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, arr, k, dp);
}

//  Tabulation Approach

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int len = 0;
        int maxi = INT_MIN;
        int maxSum = INT_MIN;
        for (int j = i; j < min(n, i + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + dp[j + 1];
            maxSum = max(maxSum, sum);
        }

        dp[i] = maxSum;
    }

    return dp[0];
}