#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> maximum(n,INT_MIN);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[j][i]>maximum[i])
            maximum[i]=matrix[j][i];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[j][i]==-1){
                matrix[j][i]=maximum[i];
            }
        }
    }

    return matrix;

}