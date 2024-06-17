#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,
vector<pair<int,int>> &vec, int row0,int col0){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    vec.push_back({row-row0, col-col0});
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,-1,0,1};

    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow,col,grid,vis,vec,row0,col0);
        }
    }
}


int numDistinctIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> st;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int , int>> vec;
                dfs(i,j,grid,vis,vec,i,j);
                st.insert(vec);
            }
        }
    }

    return st.size();
}

/*
The time complexity of the given code is O(N*M) where N is the number of rows in the 
grid and M is the number of columns in the grid. This is because in the worst case, we may have 
to visit every cell in the grid once during the DFS traversal.

The space complexity of the given code is O(N*M) as well. This is because we are using a 2D vector
'vis' to keep track of visited cells in the grid, and a set 'st' to store the distinct islands. 
Both of these data structures have a space complexity of O(N*M) in the worst case.
*/