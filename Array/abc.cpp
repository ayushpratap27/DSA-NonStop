#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        string str;
        cin>>str;
        int current=0;
        int count;
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    for(int x=1;x<4;x++){    
        for(int j=0;j<10;j++){ 
            if(str[0]==1){
            count=count+1;
            } 
            else if(str[0]==arr[j]){
            count=count+j+1;
            current=j;
            }
            if(str[x]==arr[j]){
            count=count+abs(current-j)+1;
            }
        }

    }  
    cout<<count<<endl; 
        
        
            
    }
}