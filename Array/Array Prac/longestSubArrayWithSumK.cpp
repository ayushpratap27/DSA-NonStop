#include<bits/stdc++.h>
using namespace std;

// Valid for array containing positives and zeroes
int longestSubarrayWithSumK(vector<int> nums, long long k){
    int n = nums.size();
    int left=0, right=0;
    long long sum = nums[0];
    int maxLen = 0;
    while(right < n){
        while(left <= right && sum > k){
            sum -= nums[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n){
            sum += nums[right];
        }
    }

    return maxLen;
}


