#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y; // declare x and y, so x and y has garbage value
    cin>>x>>y;// taking input of x and y

    int *ptrx=&x;// &x fetches address of x and then store it in ptrx
    int *ptry=&y;// &y fetches address of y and then store it in ptry

    int result; // declare result so it has garbage value
    int *ptr_result=&result;
    *ptr_result=*ptrx + *ptry;

    cout<<ptr_result<<endl;
}