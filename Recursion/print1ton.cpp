#include<bits/stdc++.h>
using namespace std;

void f(int n){
    //base case
    if(n<1) return;
    //assumption-->go & print first n-1 natural numbers
    f(n-1);
    cout<<n<<" ";
}

int main(){
    f(20);
    return 0;
}