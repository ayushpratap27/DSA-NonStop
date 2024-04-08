#include<bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {
    int longest = 0;
    int temp = 0;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]<nums[i+1]){
            temp++;
        }
        else{
            longest = max(longest,temp);
            temp = 0;
        }
    }
    longest = max(longest,temp);
    temp = 0;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
            temp++;
        }
        else{
            longest = max(longest,temp);
            temp = 0;
        }
    }
    longest = max(longest,temp);
    
    return longest+1;

}