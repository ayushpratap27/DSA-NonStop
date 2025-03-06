#include<iostream>
#include<vector>
using namespace std;

bool f(vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] >= nums[i + 1]){
                return false;
            }
        }
        return true;
}

bool hasIncreasingSubarrays(vector<int> &nums, int k){
    int n = nums.size();
    for (int i = 0; i <= n - 2 * k; i++){
        if (f(nums, i, k) && f(nums, i + k, k)){
            return true;
        }
    }
    return false;
}