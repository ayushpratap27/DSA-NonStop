#include<bits/stdc++.h>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    int idx=0;
    int cnt1=0;
    for(int i=0;i<n;i++){
        int tempCount=0;
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                tempCount++;
            }
        }
        if(tempCount>cnt1){
            cnt1=tempCount;
            idx=i;
        }    
    }

    return {idx,cnt1};
}