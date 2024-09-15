#include <bits/stdc++.h>
using namespace std;

long long maxScore(vector<int> &a, vector<int> &b)
{
    int n = b.size();
    if (n < 4)
        return 0;
    vector<vector<long long>> dp(5, vector<long long>(n + 1, LLONG_MIN));

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= 4; i++)
    {
        for (int j = i; j <= n; j++)
        {
            long long product = static_cast<long long>(a[i - 1]) * b[j - 1];

            long long notPick = dp[i][j - 1];
            long long pick = dp[i - 1][j - 1] + product;

            dp[i][j] = max(notPick, pick);
        }
    }

    return dp[4][n];
}