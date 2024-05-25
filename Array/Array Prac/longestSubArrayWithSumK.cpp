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


// Valid for array containing zeroes, positives and negatives
int longestSubarrayWithSumK(vector<int> nums, long long k){
    map<long long, int> preSumMap;
    long long sum=0;
    int maxLen=0;

    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(sum == k){
            maxLen=max(maxLen,i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}