#include<bits/stdc++.h>
using namespace std;

void process(int *arr,int n){
    //inside this function we have the access of the same array in the main

    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<endl;
    }
}
int main(){
    int arr[3]={5,1,2};
    process(arr,3);
}

// int main(){
//     int arr[5]={1,2,3,4,5};
//     int *ptr=(arr+2);
//     cout<<*ptr<<endl;
//     *ptr++;
//     cout<<*ptr<<endl;
// }


// We can point an entire array
int main(){
    int a[3]={11,12,13};
    int (*p)[3]=&a;
    cout<<p<<" "<<a<<" "<<*p<<" "<<*a<<endl;
}