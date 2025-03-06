#include<iostream>
#include<vector>
using namespace std;


//         Memoization Approach
int solve(int x, int y, vector<int> &dp){
    if (x <= y)
        return y - x;

    if (dp[x] != -1)
        return dp[x];

    int ans1, ans2, ans3;
    if (x % 11 == 0){
        ans1 = 1 + solve(x / 11, y, dp);
    }
    else{
        ans1 = min(x % 11 + 1 + solve(x / 11, y, dp), (11 - x % 11) + 1 + solve((x / 11) + 1, y, dp));
    }

    if (x % 5 == 0){
        ans2 = 1 + solve(x / 5, y, dp);
    }
    else{
        ans2 = min(x % 5 + 1 + solve(x / 5, y, dp), (5 - x % 5) + 1 + solve((x / 5) + 1, y, dp));
    }

    ans3 = 1 + solve(x - 1, y, dp);

    return dp[x] = min({ans1, ans2, ans3});
}

int minimumOperationsToMakeEqual(int x, int y){
    vector<int> dp(10001, -1); // Here instead of 10001 we can write x + 10, where 10 is the max we can add to x
    return solve(x, y, dp);
}



