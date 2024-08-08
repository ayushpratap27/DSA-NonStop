#include<bits/stdc++.h>
using namespace std;


//*********** Tabulation Method *************
int uniquePaths(int m, int n) {
        int dp[m][n];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }else{
                    int up = 0;
                    int left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
}

//                  Space Optimisation
int uniquePaths(int m,int n){
    vector<int> prev(n,0);

    for(int i=0;i<m;i++){

        vector<int> curr(n,0);

        for(int j=0;j<n;j++){

            if(i==0 && j==0) curr[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j-1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }

    return prev[n-1];
}

//           Combinatric Solution using nCr

int uniquePaths(int m,int n){
    int N = m + n - 2;
    int r = m-1;
    double res = 1;

    for(int i=1;i<=r;i++){
        res = res * (N-r+i)/i;
    }

    return (int)res;
}