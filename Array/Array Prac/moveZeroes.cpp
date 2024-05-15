#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n=nums.size();
    vector<int> idx;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            idx.push_back(i);
        }
    }
    for(int i=0;i<idx.size();i++){
        nums[i]=nums[idx[i]];
    }
    for(int i=idx.size();i<nums.size();i++){
        nums[i]=0;
    }
        
}