#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();

    int maximumProduct=(nums[n-1]-1)*(nums[n-2]-1);

    return maximumProduct;
}