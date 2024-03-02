#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n=matrix.size();
    vector<int> a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a.push_back(matrix[i][j]);
                
        }
    }
    sort(a.begin(),a.end());
    int result = a[k-1];
    return result;
}