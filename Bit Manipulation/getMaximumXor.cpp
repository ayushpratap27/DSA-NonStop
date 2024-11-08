#include<iostream>
#include<vector>
using namespace std;

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    int Xor = nums[0];
    int maxXor = pow(2, maximumBit) - 1;

    for (int i = 1; i < n; i++){
        Xor ^= nums[i];
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = Xor ^ maxXor;
        Xor ^= nums[n - 1 - i];
    }

    return ans;
}