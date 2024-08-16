#include<bits/stdc++.h>
using namespace std;

//           Recursive Approach
int f(int i, int j, string &s1, string &s2){
    if(i < 0) return j + 1; // length of remaining string s2
    if(j < 0) return i + 1; // length of remaining string s1

    if(s1[i] == s2[j]) return f(i-1, j-1, s1, s2);

    return min(
        1 + f(i, j-1, s1, s2), // insert
        min(
            1 + f(i-1, j, s1, s2), // delete
            1 + f(i-1, j-1, s1, s2) // replace
        )
    );
}

int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        return f(n-1, m-1, s1, s2);
}

//          Memoization 
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == 0) return j; // length of remaining string s2
        if(j == 0) return i; // length of remaining string s1

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);

        return dp[i][j] = 1 + min(
            f(i, j-1, s1, s2, dp), // insert
            min(
                f(i-1, j, s1, s2, dp), // delete
                f(i-1, j-1, s1, s2, dp) // replace
            )
        );
}
int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(n, m, s1, s2, dp);
}


//             Tabulation
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int j=1;j<=m;j++) dp[0][j] = j;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min(
                                    dp[i][j-1], // insert
                                    min(
                                    dp[i-1][j], // delete
                                    dp[i-1][j-1] // replace
                                    )
                                );
            }  
        }
    }

    return dp[n][m];
}


//         Space Optimised

int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0), curr(m+1,0);

    for(int j=0;j<=m;j++) prev[j] = j;

    for(int i=1;i<=n;i++){
        curr[0] = i;
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                curr[j] = 0 + prev[j-1];
            else {
                curr[j] = 1 + min(
                                    curr[j-1], // insert
                                    min(
                                    prev[j], // delete
                                    prev[j-1] // replace
                                    )
                                );
            }  
        }
        prev = curr;
    }

    return prev[m];
}