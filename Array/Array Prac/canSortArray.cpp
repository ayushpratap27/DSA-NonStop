#include<iostream>
#include<vector>
using namespace std;

int countSetBits(int n){
    return __builtin_popcount(n);
}

bool canSortArray(vector<int> &nums){
    int n = nums.size();
    if (n == 1)
        return true;

    for (int j = 0; j < n; j++){
        for (int i = 0; i < n - 1; i++){
            if (nums[i] > nums[i + 1]){
                if (countSetBits(nums[i]) == countSetBits(nums[i + 1]))
                    swap(nums[i], nums[i + 1]);
                else
                    return false;
            }
        }
    }

    return true;
}