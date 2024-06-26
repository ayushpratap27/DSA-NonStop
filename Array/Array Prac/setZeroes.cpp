#include<bits/stdc++.h>
using namespace std;

//*************** Brute Force ****************
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                for(int k=0; k<m; k++){
                    if(matrix[i][k] != 0){
                        matrix[i][k] = -9999;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                for(int k=0; k<n; k++){
                    if(matrix[k][j] != 0){
                        matrix[k][j] = -9999;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == -9999){
                matrix[i][j] = 0;
            }
        }
    }
}
// T.C.=O((n*m)*(n+m) + (n*m))
// S.C.=O(1)

//*************** Better Approach************
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                matrix[i][j]=0;
            }
        }
    }
       
}
// T.C.=O(n*m)  S.C.=O(n+m)

//*************** Optimal Approach************
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0){
                    matrix[0][j]=0;
                }else{
                    col0=0;
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
        
}
// T.C.=O(n*m)    S.C.=O(1)
