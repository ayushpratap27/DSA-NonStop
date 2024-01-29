#include<bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int n=nums.size();
    int x=0;
    int y=n-1;
    vector<int> result(n);
    for(int i=0;i<n;i++){
        if(nums[i]%2==0){
            result[x++]=nums[i];
        }else{
            result[y--]=nums[i];
        }
    }

    return result;
        
}