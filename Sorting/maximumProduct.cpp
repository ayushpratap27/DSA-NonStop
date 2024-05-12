#include<bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int>& nums) {
    if(nums.size()==3){
        int a = nums[0]*nums[1]*nums[2];
        return a;
    }
    else{
        sort(nums.begin(),nums.end());
        int p = nums.size();
        return max(nums[0]*nums[1]*nums[p-1],nums[p-1]*nums[p-2]*nums[p-3]);
    }
}