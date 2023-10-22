#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
        int last=arr[0];
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1];

    }
    arr[n-1]=last;

    return arr;
}


int main(){

}