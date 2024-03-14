#include<bits/stdc++.h>
using namespace std;

int findNonMinOrMax(vector<int>& nums) {
    if(nums.size()<=2){
        return -1;
    }
    int maxi=*max_element(nums.begin(),nums.end());
    int mini=*min_element(nums.begin(),nums.end());

    int result=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=maxi && nums[i]!=mini){
            return nums[i];
        }
    }
    return -1;
}