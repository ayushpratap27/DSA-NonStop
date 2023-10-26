#include<bits/stdc++.h>
using namespace std;

void spiralMatrix(vector<vector<int>> &MATRIX){
    // int n=MATRIX.size();
    // int m=MATRIX[0].size();
    int left=0,top=0;
    int right=MATRIX[0].size()-1;
    int bottom=MATRIX[0].size()-1;
    int directon=0;

    while(left<=right && top<=bottom){
        if(direction==0){
            for(int col=left;col<=right;col++){
                cout<<MATRIX[top][col]<<" ";
            }
            top++;
        }else if(direction==1){
            for(int row=top;row<=bottom;row++){
                cout<<MATRIX[row][right]<<" ";
            }
            right--;
        }else if(direction==2){
            for(int col=right;col>=left;col--){
                cout<<MATRIX[bottom][col]<<" ";
            }
            bottom--;
        }else{
            for(int row=bottom;row>=top;row--){
                cout<<MATRIX[row][left]<<" ";
            }
            left++;
        }
        direction=(direction+1)%4;
    }
}

int main(){

}