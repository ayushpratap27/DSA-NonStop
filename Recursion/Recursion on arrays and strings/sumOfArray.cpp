#include<bits/stdc++.h>
using namespace std;

int f(int *arr,int idx,int n){
    //base case
    if(idx==n-1){
        //idx is at the last index so there is only one element under consideration
        return arr[idx];
    }
    return arr[idx]+f(arr,idx+1,n);
}
int main(){
    int arr[]={2,3,5,20,1};
    int n=5;
    cout<<f(arr,0,n);

    return 0;
}