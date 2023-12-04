#include<bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1;
    int right = *max_element(nums.begin(), nums.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        int sum = 0;

        for (int num : nums) {
            sum +=ceil(static_cast<double>(num) / mid);
        }

        if (sum > threshold) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}