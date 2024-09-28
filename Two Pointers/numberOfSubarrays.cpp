#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &nums, int k){
    int n = nums.size();
    int l = 0, r = 0, cntOdd = 0, count = 0;
    while (r < n){
        cntOdd += nums[r] % 2;
        while (cntOdd > k){
            cntOdd -= nums[l] % 2;
            l++;
        }

        count += (r - l + 1);
        r++;
    }
    return count;
}

int numberOfSubarrays(vector<int> &nums, int k){
    int x = count(nums, k);
    int y = count(nums, k - 1);

    return x - y;
}