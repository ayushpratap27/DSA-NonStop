#include<bits/stdc++.h>
using namespace std;

int main(){
    int x=20;
    double dec=9.8;
    int *ptr=&x;
    double *ptrd=&dec;

    cout<<ptr<<" "<<(ptr+1)<<endl;
    cout<<ptrd<<" "<<(ptrd+1)<<endl;

    return 0;
}