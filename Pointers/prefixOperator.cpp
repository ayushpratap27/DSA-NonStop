#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[2]={7,5};
    int *ptr=&arr[0];
    cout<<*++ptr<<endl;
    cout<<arr[0]<<" "<<arr[1]<<endl;


    int a[2]={8,2};
    int *ptrf=&a[0];
    cout<<++*ptrf<<endl;
    cout<<a[0]<<" "<<a[1]<<endl;
}