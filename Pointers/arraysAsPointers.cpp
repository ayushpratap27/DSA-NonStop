#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[3]={15,12,6};
    int *ptr=&arr[0];

    cout<<ptr<<" "<<arr<<endl;
    cout<<*(arr+0)<<" "<<*(arr+1)<<endl;

    for(int i=0;i<3;i++){
        cout<<*(arr+1)<<" ";
    }
}