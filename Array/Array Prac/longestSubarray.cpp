#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums){

    int maxi = nums[0];
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] > maxi){
            maxi = nums[i];
        }
    }

    int maxLen = 0;
    int tempLen = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == maxi){
            tempLen++;
        }
        else{
            maxLen = max(maxLen, tempLen);
            tempLen = 0;
        }
    }
    maxLen = max(maxLen, tempLen);

    return maxLen;
}