#include <bits/stdc++.h>
using namespace std;

int countSubsetsWithTargetOR(vector<int> &nums, int target){
    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int num : nums){
        unordered_map<int, int> temp = dp;

        for (const auto &[orValue, count] : dp){
            int newOR = orValue | num;
            temp[newOR] += count;
        }

        dp = temp;
    }

    return dp[target];
}

int countMaxOrSubsets(vector<int> &nums){
    int maxOr = nums[0];
    for (int i = 1; i < nums.size(); i++){
        maxOr = maxOr | nums[i];
    }

    int result = countSubsetsWithTargetOR(nums, maxOr);

    return result;
}