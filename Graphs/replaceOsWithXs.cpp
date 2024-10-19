#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis){
    int n = board.size();
    int m = board[0].size();
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && board[newRow][newCol] == 'O')
            {
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }
}

void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &board,
int delrow[],int delcol[]){
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,board,delrow,delcol);
            }
        }
}

void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));
        // Traverse first row and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,vis,board,delrow,delcol);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1,j,vis,board,delrow,delcol);
            }
        }
        // Traverse first col and last col
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board,delrow,delcol);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,vis,board,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
}

/*
The time complexity of this solution is O(n*m) where n is the number of rows and 
m is the number of columns in the board. This is because in the worst case scenario,
we may have to visit every cell in the board.

The space complexity is also O(n*m) because we are using a 2D vector to keep track of
visited cells in the board.
*/