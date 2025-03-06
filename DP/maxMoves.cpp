#include <iostream>
#include <vector>
using namespace std;

int f(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
    int n = grid.size();
    int m = grid[0].size();
    if (row >= n || col >= m || row < 0 || col < 0)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int ans1 = 0, ans2 = 0, ans3 = 0;
    if (row - 1 >= 0 && col + 1 < m && grid[row - 1][col + 1] > grid[row][col]){
        ans1 = 1 + f(row - 1, col + 1, grid, dp);
    }
    if (col + 1 < m && grid[row][col + 1] > grid[row][col]){
        ans2 = 1 + f(row, col + 1, grid, dp);
    }
    if (row + 1 < n && col + 1 < m && grid[row + 1][col + 1] > grid[row][col]){
        ans3 = 1 + f(row + 1, col + 1, grid, dp);
    }

    return dp[row][col] = max({ans1, ans2, ans3});
}

int maxMoves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    int maxAns = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++){
        ans = f(i, 0, grid, dp);
        cout << ans << endl;
        maxAns = max(maxAns, ans);
    }

    return maxAns;
}
