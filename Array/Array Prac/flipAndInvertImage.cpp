#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int n=image.size();
    //for(int i=0;i<n;i++) {
    //    vector<int>& row = image[i];
    //    reverse(row.begin(), row.end());
    //}
    for(int i=0;i<image[0].size();i++){
        reverse(image[i].begin(),image[i].end());
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          image[i][j] = 1 - image[i][j] ;
        }
    }

    return image;
}