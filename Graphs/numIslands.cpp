#include<bits/stdc++.h>
using namespace std;

// void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
//     int n = grid.size();
//     int m = grid[0].size();
//     vis[row][col] = 1;
//     int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//     for (auto &dir : directions)
//     {
//         int newRow = row + dir[0];
//         int newCol = col + dir[1];

//         if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
//             !vis[newRow][newCol] && grid[newRow][newCol] == '1')
//         {
//             dfs(newRow, newCol, grid, vis);
//         }
//     }
// }

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    if((delrow == 0 && delcol == 0) || abs(delrow) + abs(delcol) > 1) {
                        continue;
                    }
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
}

int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
}

/*
The time complexity of this BFS algorithm is O(n*m) where n is the number of rows and m 
is the number of columns in the grid. This is because in the worst case scenario, we may have 
to visit every cell in the grid once.

The space complexity is also O(n*m) because we are using a queue to store the cells to be visited,
and in the worst case scenario, the queue may contain all the cells in the grid. Additionally, we 
are using a 2D array 'vis' to keep track of visited cells, which also takes up O(n*m) space.
*/