#include<bits/stdc++.h>
using namespace std;

//Base case: If array is empty print nothing
//Assumption:f(arr,idx+1,n)
//Self work: Print the element at the current index

void f(int *arr,int idx, int n){
    //base case
    if(idx==n) return;
    //self work
    cout<<arr[idx]<<endl;
    //assume that
    f(arr,idx+1,n);//assume it works correctly--> it will print the remaining arr
}

int main(){
    int n=5;
    int arr[]={6,1,9,3,4};
    f(arr,0,n);

    return 0;
}