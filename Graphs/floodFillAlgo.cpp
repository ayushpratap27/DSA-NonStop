#include<bits/stdc++.h>
using namespace std;

// void bfs(int row, int col, vector<vector<int>> &image,
//          vector<vector<int>> &ans, int initialColor, int color)
// {
//     int n = image.size();
//     int m = image[0].size();
//     ans[row][col] = color;
//     queue<pair<int, int>> q;
//     q.push({row, col});
//     while (!q.empty())
//     {
//         int r = q.front().first;
//         int c = q.front().second;
//         q.pop();
//         int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//         for (auto &dir : directions)
//         {
//             int newRow = r + dir[0];
//             int newCol = c + dir[1];

//             if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
//                 ans[newRow][newCol] != color && image[newRow][newCol] == initialColor)
//             {
//                 ans[newRow][newCol] = color;
//                 q.push({newRow, newCol});
//             }
//         }
//     }
// }

void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>> &image,
int newColor,int delRow[],int delCol[],int iniColor){
    ans[row][col]=newColor;
    int n=image.size();
    int m=image[0].size();

    for(int i=0;i<4;i++){
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor &&
        ans[nrow][ncol]!=newColor){
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor){
    
    int iniColor=image[x][y];
    vector<vector<int>> ans=image;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};

    dfs(x,y,ans,image,newColor,delRow,delCol,iniColor);

    return ans;
}

/*
The time complexity of the floodFill function is O(n*m) where n is the number of rows 
and m is the number of columns in the image matrix. This is because in the worst case 
scenario, the function may need to visit every cell in the matrix to perform the flood fill operation.

The space complexity of the floodFill function is also O(n*m) because we are using a separate 
2D matrix to store the result of the flood fill operation, which has the same dimensions as the 
input image matrix. Additionally, the recursive calls in the DFS function may consume additional 
space on the call stack, but it is bounded by the size of the input matrix.

Overall, the time and space complexity of the floodFill function is O(n*m) due to the need to visit 
every cell in the matrix and store the result of the flood fill operation in a separate matrix.
*/