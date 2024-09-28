#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &nums, int k){
    int n = nums.size();
    unordered_map<int, int> mp;
    int l = 0, r = 0, count = 0;

    while (r < n){
        mp[nums[r]]++;
        while (mp.size() > k){
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }

        if (mp.size() <= k){
            count += (r - l + 1);
        }
        r++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k){
    int x = count(nums, k);
    int y = count(nums, k - 1);

    return x - y;
}