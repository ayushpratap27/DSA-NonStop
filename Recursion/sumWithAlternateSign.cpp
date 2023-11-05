#include<bits/stdc++.h>
using namespace std;

int f(int n){
    //base case
    if(n==0) return 0;
    //assumption
    return f(n-1)+((n%2==0)? (-n):(n));//calculate sum of first n-1 natural num
    // with alternate  sign, and we will add contri. of n
}

int main(){
    cout<<f(10)<<endl;
}