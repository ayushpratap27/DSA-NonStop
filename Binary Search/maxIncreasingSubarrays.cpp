#include<iostream>
#include<vector>
using namespace std;

bool canFindAdjIncSubarrays(vector<int>& lengths, int k, int n) {
    for (int i = 0; i <= n - 2 * k; i++){
        if (lengths[i] >= k && lengths[i + k] >= k){
            return true;
        }
    }
    return false;
}

int maxIncreasingSubarrays(vector<int> &nums){
    int n = nums.size();

    vector<int> lengths(n, 1);
    for (int i = n - 2; i >= 0; i--){
        if (nums[i] < nums[i + 1]){
            lengths[i] = lengths[i + 1] + 1;
        }
    }

    int left = 1;
    int right = n / 2;
    int result = 0;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (canFindAdjIncSubarrays(lengths, mid, n)){
            result = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return result;
}
