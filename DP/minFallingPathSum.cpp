#include<bits/stdc++.h>
using namespace std;

//         Using recursion
int f(int i,int j,vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    if(j<0 || j>=m) return 1e9;
    if(i == 0) return matrix[0][j];

    int straight = matrix[i][j] + f(i-1,j,matrix);
    int leftDiagonal = matrix[i][j] + f(i-1,j-1,matrix);
    int rightDiagonal = matrix[i][j] + f(i-1,j+1,matrix);

    return min(straight, min(leftDiagonal, rightDiagonal));
        
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
        
    int mini = 1e9;
    for(int j=0;j<n;j++){
        mini = min(mini, f(n-1,j,matrix));
    }
        
    return mini;
    
}

//         Using Tabulation
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
        
    for(int j=0;j<m;j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){

            int straight = matrix[i][j] + dp[i-1][j];

            int leftDiagonal = matrix[i][j];
            if(j-1 >= 0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += 1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1 < m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += 1e9;

            dp[i][j] = min(straight, min(leftDiagonal, rightDiagonal));
        }
    }

    int mini = 1e9;
    for(int j=0;j<m;j++){
        mini = min(mini, dp[n-1][j]);
    }
    
    return mini;
}

//        Space Optimised
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m,0), curr(m,0);
        
    for(int j=0;j<m;j++){
        prev[j] = matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){

            int straight = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if(j-1 >= 0) leftDiagonal += prev[j-1];
            else leftDiagonal += 1e9;

            int rightDiagonal = matrix[i][j];
            if(j+1 < m) rightDiagonal += prev[j+1];
            else rightDiagonal += 1e9;

            curr[j] = min(straight, min(leftDiagonal, rightDiagonal));
        }
        prev = curr;
    }

    int mini = 1e9;
    for(int j=0;j<m;j++){
        mini = min(mini, prev[j]);
    }
        
    return mini;
}