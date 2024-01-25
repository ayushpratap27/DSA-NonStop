#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
        
    sort(nums.begin(), nums.end());
        
    return nums[nums.size()-k];
}