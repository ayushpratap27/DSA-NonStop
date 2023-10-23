#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int x;

    for(int p=0;p<=n;p++){
        for(int i=0;i<n;i++){
            if(nums[i]==p){
                continue;
            }else{
                x=p;
            }
        }
    }

    return x;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        

    }  
   
}