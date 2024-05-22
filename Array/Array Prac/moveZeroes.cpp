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
//************** In place ****************
void moveZeroes(vector<int>& nums) {
    int k=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[k++]=nums[i];
        }
    }
    for(int i=k;i<nums.size();i++){
        nums[i]=0;
    }
}

//************** In place Using Two Pointers***********

void moveZeroes(vector<int>& nums) {
    int i=0,j=0;
    while(i<nums.size() && j<nums.size()){
        if(nums[j]!=0){
            swap(nums[i++],nums[j++]);
        }
        else{
            j++;
        }
    }
}