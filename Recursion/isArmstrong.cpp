#include<bits/stdc++.h>
using namespace std;

int pow_recursive(int p,int q){
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

int f(int n,int d){
    if(n==0) return 0;// base case
    return pow_recursive(n%10,d)+f(n/10,d);
}

int main(){
    int n;
    cin>>n;
    int no_of_digit=0;
    int temp=n;
    while(temp>0){
        temp=temp/10;
        no_of_digit++;
    }
    int result=f(n,no_of_digit);
    if(result==n){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}