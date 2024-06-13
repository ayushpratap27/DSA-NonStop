#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair< pair<int,int>, int>> q;
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            }
        }

        int time = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow,ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
}

/*
The time complexity of this solution is O(n*m) where n is the number of rows and m is the number
of columns in the grid. This is because in the worst case scenario, we may have to visit every 
cell in the grid.

The space complexity of this solution is also O(n*m) because we are using a queue to perform a 
breadth-first search traversal of the grid, and we are also using a 2D array to keep track of 
visited cells.
*/