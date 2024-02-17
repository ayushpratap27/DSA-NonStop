#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums) {
    if(nums.size()<2){
        return nums[0];
    }
    long long int maximum = INT_MIN;
    long long sum = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum>maximum){
            maximum = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return maximum;
}