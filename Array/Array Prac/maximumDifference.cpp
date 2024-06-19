#include<bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    if(n < 2){
        return -1;
    }

    int minVal = nums[0];
    int maxDiff = -1;

    for(int j=1;j<n;j++){
        if(nums[j] > minVal){
            maxDiff = max(maxDiff, nums[j] - minVal);
        }
        minVal = min(minVal, nums[j]);
    }

    return maxDiff;
}