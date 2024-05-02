#include<bits/stdc++.h>
using namespace std;

int findMaxK(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int i = 0;
    int j = nums.size()-1;
    while(i<=j){
        if(-1*nums[i]==nums[j]){
            return nums[j];
        }
        else if(-1*nums[i] < nums[j]){
            j--;
        }
        else if(-1*nums[i]>nums[j]){
            i++;
        }
    }
    return -1;
}