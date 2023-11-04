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


// ************ More Efficient Way ***************

int f(int p,int q){
    //base case
    if(q==0) return 1;
    if(q%2==0){
        //if q is even
        int result=f(p,q/2);
        return result*result;
    }else{
        //if q is odd
        int result=f(p,(q-1)/2);
        return p*result*result;
    }
}

int main(){
    int res=f(2,5);
    cout<<res;
    return 0;
}