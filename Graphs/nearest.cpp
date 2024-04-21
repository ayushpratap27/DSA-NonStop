#include<bits/stdc++.h>
using namespace std;

vector <vector<int>> nearest(vector<vector<int>> &mat,int n,int m){
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]==1) {
                q.push(make_pair(make_pair(i, j), 0)); 
                vis[i][j]=1;
            } else {
                vis[i][j]=0;
            }
        }
    }

    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};

    while(!q.empty()) {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        dist[row][col]=steps;

        for(int i=0;i<4;i++) {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push(make_pair(make_pair(nrow, ncol), steps + 1)); 
            }
        }
    }

    return dist;
}


// vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
//     int m = mat.size(), n = mat[0].size(), INF = m + n; 
//     for (int r = 0; r < m; r++) {
//         for (int c = 0; c < n; c++) {
//             if (mat[r][c] == 0) continue;
//             int top = INF, left = INF;
//             if (r - 1 >= 0) top = mat[r - 1][c];
//             if (c - 1 >= 0) left = mat[r][c - 1];
//             mat[r][c] = min(top, left) + 1;
//         }
//     }
//     for (int r = m - 1; r >= 0; r--) {
//         for (int c = n - 1; c >= 0; c--) {
//             if (mat[r][c] == 0) continue;
//             int bottom = INF, right = INF;
//             if (r + 1 < m) bottom = mat[r + 1][c];
//             if (c + 1 < n) right = mat[r][c + 1];
//             mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
//         }
//     }
//     return mat;
// }