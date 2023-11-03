#include<bits/stdc++.h>
using namespace std;

//Given two numbers p and q, find the value p^q using a recursive function

int f(int p,int q){
    //base case
    if(q==0) return 1;
    return p*f(p,q-1);
}

int main(){
    int p,q;
    cin>>p>>q;

    int ans=f(p,q);
    cout<<ans<<endl;
}