#include<bits/stdc++.h>
using namespace std;

int main(){
    int x=18;
    int *ptr=&x;

    *ptr=50;
    cout<<"New value of x "<<x<<endl;
    cout<<"New value pointed by ptr "<<*ptr<<endl;
}