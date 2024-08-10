#include<bits/stdc++.h>
using namespace std;

//               Using Memoization

int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp){
    int n = triangle.size(); 
    if(i == n-1) return triangle[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + f(i+1,j,triangle,dp);
    int side = triangle[i][j] + f(i+1,j+1,triangle,dp);

    return dp[i][j] = min(down,side);
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n,-1));

    return f(0,0,triangle,dp);
}

//             Using Tabulation

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n,0));

    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

//           Space Optimised

int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0), curr(n,0);

        for(int j=0;j<n;j++){
            front[j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];
                curr[j] = min(down, diagonal);
            }
            front = curr;
        }

        return front[0];
}

