#include<bits/stdc++.h>
using namespace std;

// int findKthLargest(vector<int>& nums, int k) {
        
//     sort(nums.begin(), nums.end());
        
//     return nums[nums.size()-k];
// }

vector<int> Klargest(vector<int> &a, int k, int n) {
    sort(a.begin(), a.end());

    vector<int> result(a.end() - k, a.end());
    return result;
}

