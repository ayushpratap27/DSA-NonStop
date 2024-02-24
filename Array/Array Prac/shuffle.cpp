#include<bits/stdc++.h>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> vec;
    for(int i=0;i<n;i++){
        vec.push_back(nums[i]);
        vec.push_back(nums[n+i]);
    }

    return vec;
    
}