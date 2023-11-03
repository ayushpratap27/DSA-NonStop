#include<bits/stdc++.h>
using namespace std;

// Given an integer,find out the sum of its digits using recursion

int f(int n){
    //base case
    if(n>=0 && n<=9) return n;
    return f(n/10) + (n%10);
}

int main(){
    int result=f(1234);
    cout<<result;
}