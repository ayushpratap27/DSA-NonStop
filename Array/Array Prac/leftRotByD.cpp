#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    int n=arr.size();
    int p=1;
    while(p<=k){
        int last=arr[0];
        for(int i=0;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        arr[n-1]=last;
        p++;
    }
    return arr;

}


int main(){

}