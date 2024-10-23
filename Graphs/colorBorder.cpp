#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> res = grid;
    queue<pair<int, int>> q;
    int iniColor = grid[row][col];
    q.push({row, col});
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[row][col] = 1;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == iniColor){
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1){
            res[r][c] = color;
        }
        else if (grid[r - 1][c] != iniColor || grid[r][c + 1] != iniColor || grid[r + 1][c] != iniColor || grid[r][c - 1] != iniColor){
            res[r][c] = color;
        }
    }
    return res;
}