#include<bits/stdc++.h>
using namespace std;

int maxProductDifference(vector<int>& nums) {
    int n=nums.size();

    sort(nums.begin(),nums.end());
    int product = (nums[n-1]*nums[n-2]) - (nums[0]*nums[1]);

    return product;
}