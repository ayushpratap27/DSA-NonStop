#include<bits/stdc++.h>
using namespace std;

//             Using Memoisation

int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(i == 0 && j == 0) return grid[i][j];
    if(i < 0 || j < 0) return 1e9;

    if(dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + f(i-1,j,grid,dp);
    int left = grid[i][j] + f(i,j-1,grid,dp);

    return dp[i][j] = min(up,left);
}

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
        
    return f(n-1,m-1,grid,dp);
}

//          Using Tabulation

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                int up = 0;
                if(i > 0) up = grid[i][j] + dp[i-1][j];
                else up += 1e9;

                int left = 0;
                if(j > 0) left = grid[i][j] + dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}

//          Space Optimised
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
        
    vector<int> prev(m,0);
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0) curr[j] = grid[i][j];
            else{
                int up = 0;
                if(i > 0) up = grid[i][j] + prev[j];
                else up += 1e9;

                int left = 0;
                if(j > 0) left = grid[i][j] + curr[j-1];
                else left += 1e9;

                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}


/*
The time complexity of this solution is O(n*m), where n is the number of rows in the grid 
and m is the number of columns in the grid. This is because we iterate through each cell in 
the grid once and perform constant time operations.

The space complexity is O(m), where m is the number of columns in the grid. This is because 
we only use two vectors of size m to store the minimum path sum values for the current row and 
the previous row.

*/